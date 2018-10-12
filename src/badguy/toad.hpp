//  Toad - A jumping toad
//  Copyright (C) 2006 Christoph Sommer <christoph.sommer@2006.expires.deltadevelopment.de>
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

#ifndef HEADER_SUPERTUX_BADGUY_TOAD_HPP
#define HEADER_SUPERTUX_BADGUY_TOAD_HPP

#include "badguy/badguy.hpp"

/**
 * Badguy "Toad" - A jumping toad
 */
class Toad : public BadGuy
{
public:
  Toad(const ReaderMapping& reader);

  virtual void initialize() override;
  virtual void collision_solid(const CollisionHit& hit) override;
  virtual HitResponse collision_badguy(BadGuy& badguy, const CollisionHit& hit) override;
  virtual bool collision_squished(GameObject& object) override;
  virtual void active_update(float elapsed_time) override;

  virtual void unfreeze() override;
  virtual bool is_freezable() const override;
  virtual std::string get_class() const override {
    return "toad";
  }
  virtual std::string get_display_name() const override {
    return _("Toad");
  }

  virtual void after_editor_set() override;

protected:
  enum ToadState {
    IDLE,
    JUMPING,
    FALLING
  };

private:
  void set_state(ToadState newState);

private:
  Timer recover_timer;
  ToadState state;
};

#endif

/* EOF */
