// SPDX-License-Identifier: LGPL-3.0-only

#pragma once

#include "cog2d/input/controller.hpp"

COG2D_NAMESPACE_BEGIN_DECL

class KeyboardController : public Controller
{
	COG2D_CONTROLLER_TYPE(1)

public:
	KeyboardController();

	void event(SDL_Event* ev) override;
};

COG2D_NAMESPACE_END_DECL
