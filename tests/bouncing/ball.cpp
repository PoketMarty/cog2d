#include "ball.hpp"

#include <iostream>

#include <graphicsengine.hpp>

constexpr float RADIUS = 50.f;

Ball::Ball():
	Actor()
{
	m_bbox = {0, 0, RADIUS*2, RADIUS*2};
	m_vel = {2, 2};
}

Ball::Ball(Vector pos, Vector vel):
	Actor()
{
	m_bbox = {pos.x, pos.y, RADIUS*2, RADIUS*2};
	m_vel = vel;
}

void Ball::update()
{
	bool hor = check_horizontal_bound();
	bool ver = check_vertical_bound();

	/*
	if (hor) {
		m_vel.x = -m_vel.x;
	}

	if (ver) {
		m_vel.y = -m_vel.y;
	}
	*/

	if(hor || ver)
		m_col = m_col == 0xFF0000FF ? 0xFFFFFFFF : 0xFF0000FF;

	m_vel.x *= hor ? -1 : 1;
	m_vel.y *= ver ? -1 : 1;

	if (hor && ver) {
		std::cout << "CORNER!!!!" << std::endl;
	}

	Actor::update();
}

void Ball::draw()
{
	GraphicsEngine::get().draw_circle({m_bbox.pos.x + RADIUS, m_bbox.pos.y + RADIUS}, RADIUS, true, m_col);
}

bool Ball::check_horizontal_bound()
{
	int w = -1;
	SDL_GetWindowSize(GraphicsEngine::get().get_window(), &w, nullptr);

	return m_bbox.pos.x < 0.f || m_bbox.pos.x + m_bbox.size.x > static_cast<float>(w);
}

bool Ball::check_vertical_bound()
{
	int h = -1;
	SDL_GetWindowSize(GraphicsEngine::get().get_window(), nullptr, &h);

	return m_bbox.pos.y < 0.f || m_bbox.pos.y + m_bbox.size.y > static_cast<float>(h);
}
