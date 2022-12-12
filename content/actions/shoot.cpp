#include "shoot.h"

#include "actor.h"
#include "animatedsprite.h"
#include "attack.h"
#include "engine.h"
#include "projectile.h"
#include "tile.h"

Shoot::Shoot() {}

Result Shoot::perform(Engine& engine) {
    starting_position = actor->get_position();
    direction = actor->get_direction();
    new_position = starting_position + direction;
    Tile& tile = engine.dungeon.tiles(new_position);
    while (!tile.is_wall() || !tile.actor || !tile.is_door()) {
        Tile& tile = engine.dungeon.tiles(new_position);
        new_position = new_position + direction;
        if (tile.is_door()) {
            Door& door = engine.dungeon.doors.at(new_position);
            if (!door.is_open()) {
                break;
            }
        }
        ending_position = new_position;
        new_position = new_position + direction;
    }
    ending_position = new_position;
    arrow = engine.graphics.get_sprite("arrow");
    if (tile.actor) {
        engine.events.add(Projectile{arrow, direction, starting_position,
                                     ending_position, damage});
    }
    return success();
}
