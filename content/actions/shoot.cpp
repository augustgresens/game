#include "shoot.h"

#include "actor.h"
#include "animatedsprite.h"
#include "attack.h"
#include "engine.h"
#include "grid.h"
#include "projectile.h"
#include "tile.h"

Result Shoot::perform(Engine& engine) {
    Vec direction = actor->get_direction();
    Vec starting_position = actor->get_position();
    Vec new_position = starting_position + direction;
    Tile& tile = engine.dungeon.tiles(new_position);
    while (!tile.is_wall() && !tile.actor && !tile.is_door()) {
        if (tile.is_door()) {
            Door& door = engine.dungeon.doors.at(new_position);
            if (!door.is_open()) {
                break;
            }
        }
        if (!engine.dungeon.tiles.within_bounds(new_position)) {
            new_position = new_position - direction;
            break;
        }
        new_position = new_position + direction;
        tile = engine.dungeon.tiles(new_position);
    }
    Vec ending_position = new_position;
    arrow = engine.graphics.get_sprite("arrow");
    if (tile.actor) {
        actor->attack(*tile.actor);
    } else {
        engine.events.add(Projectile{arrow, direction, starting_position,
                                     ending_position, 0});
    }
    return success();
}