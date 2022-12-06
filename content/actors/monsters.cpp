#include "monsters.h"

#include "axe.h"
#include "engine.h"
#include "knife.h"
#include "monstertype.h"
#include "move.h"
#include "none.h"
#include "randomness.h"
#include "rest.h"
#include "sword_big.h"
#include "wander.h"

namespace Monsters {
MonsterType goblin() {
    int health = 2;
    return {"goblin", default_speed, health, std::make_shared<Knife>(2),
            default_behavior};
}
MonsterType orc_masked() {
    int health = 2;
    return {"orc_masked", default_speed, health, std::make_shared<Axe>(4),
            default_behavior};
}
MonsterType demon() {
    int health = 2;
    return {"demon", default_speed, health, std::make_shared<None>(),
            default_behavior};
}
MonsterType demon_big() {
    int health = 2;
    return {"demon_big", default_speed, health, std::make_shared<None>(),
            default_behavior};
}
MonsterType muddy() {
    int health = 2;
    return {"muddy", default_speed, health, std::make_shared<Knife>(2),
            default_behavior};
}
MonsterType ogre() {
    int health = 2;
    return {"ogre", default_speed, health, std::make_shared<Axe>(4),
            default_behavior};
}
std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me) {
    // pursue Hero if monster can see him (If Hero sees me, I see him)
    if (me.is_visible() && engine.hero) {
        Vec from = me.get_position();
        Vec to = engine.hero->get_position();
        std::vector<Vec> path = engine.dungeon.calculate_path(from, to);
        if (path.size() > 1) {
            Vec direction = path.at(1) - path.at(0);
            return std::make_unique<Move>(direction);
        }
    }
    // Monster doesn't see Hero
    if (probability(66)) {
        return std::make_unique<Wander>();
    } else {
        return std::make_unique<Rest>();
    }
}
}  // namespace Monsters
