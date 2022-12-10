#include "shoot.h"

#include "attack.h"
#include "engine.h"
#include "projectile.h"

Shoot::Shoot(Actor& defender, Vec direction)
    : defender{defender}, direction{direction} {}

Result Shoot::perform(Engine& engine) {
    starting_position = actor->get_position();
    while (open_tile) {
        new_position = actor->get_position() + direction;
        Tile& tile = engine.dungeon.tiles(new_position);
        if (tile.is_wall()) {
            open_tile = false;
        } else if (tile.is_door()) {
            Door& door = engine.dungeon.doors.at(new_position);
            if (!door.is_open()) {
                open_tile = false;
            }
        } else if (tile.actor) {
            open_tile = false;
            return alternative(Attack{*tile.actor});  // alternative here?
        }                                             // increment tiles
    }

    return success();  // return the distance?
}

// If the position is at 0,0 and the direction is facing right does position +
// direction equal 1,0