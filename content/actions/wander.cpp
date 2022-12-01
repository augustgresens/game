#include "wander.h"

#include "actor.h"
#include "engine.h"
#include "monster.h"
#include "move.h"
#include "randomness.h"
#include "rest.h"

Result Wander::perform(Engine& engine) {
    Vec pos = actor->get_position();
    std::vector<Vec> neighbors = engine.dungeon.neighbors(pos);

    shuffle(std::begin(neighbors), std::end(neighbors));
    for (const Vec& neighbor : neighbors) {
        Tile& tile = engine.dungeon.tiles(neighbor);
        if (!tile.is_wall() && !tile.actor) {
            Vec direction = neighbor - pos;
            return alternative(Move{direction});
        }
    }
    return alternative(Rest{});
}