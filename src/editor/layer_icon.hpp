//  SuperTux
//  Copyright (C) 2015 Hume2 <teratux.mail@gmail.com>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include "editor/object_icon.hpp"

class LayerObject;
class TileMap;

class LayerIcon : public ObjectIcon
{
public:
  LayerIcon(LayerObject* layer);
  ~LayerIcon() override {}

  virtual void draw(DrawingContext& context, const Vector& pos) override;
  virtual void draw(DrawingContext& context, const Vector& pos, int pixels_shown) override;

  int get_zpos() const;
  bool is_valid() const;

  inline LayerObject* get_layer() const { return m_layer; }
  inline TileMap* get_layer_tilemap() const { return m_layer_tilemap; }

private:
  LayerObject* m_layer;
  TileMap* m_layer_tilemap;

  SurfacePtr m_selection;

private:
  LayerIcon(const LayerIcon&) = delete;
  LayerIcon& operator=(const LayerIcon&) = delete;
};
