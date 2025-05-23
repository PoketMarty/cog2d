// SPDX-License-Identifier: LGPL-3.0-only

#pragma once

#include <SDL2/SDL.h>

#include "cog2d/input/controller.hpp"

COG2D_NAMESPACE_BEGIN_DECL

class JoypadController : public Controller
{
	COG2D_CONTROLLER_TYPE(2)

public:
	SDL_JoystickID m_device_id;

public:
	JoypadController(SDL_JoystickID id);
	~JoypadController();

	virtual void event(SDL_Event* ev) override;
};

COG2D_NAMESPACE_END_DECL
