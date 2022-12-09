#include "shoot.h"

#include "engine.h"

Shoot::Shoot(Actor& defender, Vec direction)
    : defender{defender}, direction{direction} {}

Result Shoot::perform(Engine& engine) {
    starting_position = actor->get_position();
    while (open_tile) {
        new_position = actor->get_position() + direction;
        Tile& tile = engine.dungeon.tiles(new_position);
        if (tile.is_wall()) {
            open_tile = false;
            target_wall_door = true;
        } else if (tile.is_door()) {
            Door& door = engine.dungeon.doors.at(new_position);
            if (!door.is_open()) {
                open_tile = false;
                target_wall_door = true;
            }
        } else if (tile.actor) {
            open_tile = false;
            target_actor = true;
            actor->attack(defender);
        }  // increment tiles
    }
    Vec distance =
        new_position - starting_position;  // Maybe make this public data?
    return success();                      // return the distance?
}

// If the position is at 0,0 and the direction is facing right does position +
// direction equal 1,0