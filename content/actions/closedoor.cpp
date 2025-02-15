#include "closedoor.h"

#include "actor.h"
#include "engine.h"
#include "updatefov.h"

Result CloseDoor::perform(Engine& engine) {
    Vec position = actor->get_position();
    std::vector<Vec> neighbors = engine.dungeon.neighbors(position);
    bool closed_any_doors = false;
    for (const Vec& neighbor : neighbors) {
        Tile& tile = engine.dungeon.tiles(neighbor);
        if (tile.is_door()) {
            Door& door = engine.dungeon.doors.at(neighbor);
            door.close();
            closed_any_doors = true;
        } else {
            closed_any_doors = false;
        }
    }
    if (closed_any_doors) {
        engine.events.add(UpdateFOV{});  // Similar event for adding projectiles
        return success();
    } else {
        return failure();
    }
}