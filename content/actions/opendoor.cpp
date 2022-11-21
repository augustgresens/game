#include "opendoor.h"

#include "actor.h"
#include "engine.h"

Result OpenDoor::perform(Engine& engine) {
    Vec position = actor->get_position();
    std::vector<Vec> neighbors = engine.dungeon.neighbors(position);
    bool opened_any_doors = false;
    for (const Vec& neighbor : neighbors) {
        Tile& tile = engine.dungeon.tiles(neighbor);
        if (tile.is_door()) {
            Door& door = engine.dungeon.doors.at(neighbor);
            door.open();
            opened_any_doors = true;
        } else {
            opened_any_doors = false;
        }
    }
    if (opened_any_doors) {
        return success();
    } else {
        return failure();
    }
}