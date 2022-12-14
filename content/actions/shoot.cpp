#include "shoot.h"

#include "hit.h"
#include "projectile.h"

Shoot::Shoot() {}

Result Shoot::perform(Engine& engine) {
    Vec direction = actor->get_direction();
    Vec starting_position = actor->get_position();
    Vec new_position = starting_position + direction;
    Tile tile = engine.dungeon.tiles(new_position);
    while (!tile.is_wall() && !tile.actor) {
        if (tile.is_door()) {
            Door& door = engine.dungeon.doors.at(new_position);
            if (!door.is_open()) {
                break;
            }
        }
        new_position = new_position + direction;
        tile = engine.dungeon.tiles(new_position);
    }
    int projectile_length =
        static_cast<int>(distance(new_position, starting_position));
    Projectile{direction, starting_position, projectile_length};
    if (tile.actor) {
        engine.events.add(Hit{*tile.actor, 4});
    }
    return success();
}