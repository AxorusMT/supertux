//  SuperTux
//  Copyright (C) 2006 Matthias Braun <matze@braunis.de>
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

#ifndef HEADER_SUPERTUX_OBJECT_ROCK_HPP
#define HEADER_SUPERTUX_OBJECT_ROCK_HPP

#include "object/moving_sprite.hpp"
#include "object/portable.hpp"
#include "scripting/exposed_object.hpp"
#include "scripting/rock.hpp"
#include "supertux/physic.hpp"

class Rock : public MovingSprite,
             public Portable,
             public ExposedObject<Rock, scripting::Rock>
{
public:
  Rock(const Vector& pos, const std::string& spritename);
  Rock(const ReaderMapping& reader);
  Rock(const ReaderMapping& reader, const std::string& spritename);

  virtual void collision_solid(const CollisionHit& hit) override;
  virtual HitResponse collision(GameObject& other, const CollisionHit& hit) override;
  virtual void update(float elapsed_time) override;

  virtual void grab(MovingObject& object, const Vector& pos, Direction dir) override;
  virtual void ungrab(MovingObject& object, Direction dir) override;
  virtual std::string get_class() const override {
    return "rock";
  }
  virtual std::string get_display_name() const override {
    return _("Rock");
  }
  virtual ObjectSettings get_settings() override;

protected:
  Physic physic;
  bool on_ground;
  bool grabbed;
  Vector last_movement;
  std::string on_grab_script;
  std::string on_ungrab_script;
};

#endif

/* EOF */
