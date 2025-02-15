#pragma once
#include "action.h"
#include "monster.h"

namespace Monsters {
MonsterType goblin();
MonsterType orc_masked();
MonsterType demon();
MonsterType demon_big();
MonsterType muddy();
MonsterType ogre();
constexpr int default_speed{8};
std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me);
}  // namespace Monsters