// SPDX-License-Identifier: LGPL-3.0-only

#pragma once

#include <filesystem>
#include <string>
#include <unordered_map>
#include <list>

#include "cog2d/assets/assetcollection.hpp"
#include "cog2d/util/currenton.hpp"

COG2D_NAMESPACE_BEGIN_DECL

#define COG2D_USE_ASSETMANAGER COG2D_USING(AssetManager, assetmanager)
class AssetManager : public Currenton<AssetManager>
{
public:
	PixmapCollection pixmaps;

public:
	AssetManager();
};

COG2D_NAMESPACE_END_DECL
