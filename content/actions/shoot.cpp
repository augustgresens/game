#include "shoot.h"

#include "actor.h"
#include "animatedsprite.h"
#include "attack.h"
#include "engine.h"
#include "projectile.h"
#include "tile.h"

Result Shoot::perform(Engine& engine) {
    starting_position = actor->get_position();
    direction = actor->get_direction();
    new_position = starting_position + direction;
    Tile& tile = engine.dungeon.tiles(new_position);
    while (!tile.is_wall() && !tile.actor && !tile.is_door()) {
        Tile& tile = engine.dungeon.tiles(new_position);
        if (tile.is_door()) {
            Door& door = engine.dungeon.doors.at(new_position);
            if (!door.is_open()) {
                break;
            }
        }
        new_position = new_position + direction;
    }
    ending_position = new_position;
    arrow = engine.graphics.get_sprite("arrow");
    if (tile.actor) {
        actor->attack(*tile.actor);
    } else {
        engine.events.add(Projectile(arrow, direction, starting_position,
                                     ending_position, 0));
    }
    return success();
}

// Dont call the arrow anywhere
