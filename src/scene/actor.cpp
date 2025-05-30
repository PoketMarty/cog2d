// SPDX-License-Identifier: LGPL-3.0-only

#include "actor.hpp"

#include "cog2d/program.hpp"

COG2D_NAMESPACE_BEGIN_IMPL

Actor::Actor()
    : CollisionBody(),
      m_vel(0, 0),
      m_accel(0, 0),
      m_grav(0)
{
}

void Actor::update()
{
	if (m_grav != 0)
		gravity();
	m_mov = m_vel;
}

void Actor::gravity()
{
	// This function hates operator overloads, so just add the x and y seperately.
	m_vel.x += m_accel.x * Program::get().m_delta_time;
	m_vel.y += (m_accel.y + m_grav) * Program::get().m_delta_time;
}

COG2D_NAMESPACE_END_IMPL
