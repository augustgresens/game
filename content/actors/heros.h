#pragma once

#include "actor.h"
#include "bow.h"
#include "closedoor.h"
#include "herotype.h"
#include "mace.h"
#include "move.h"
#include "none.h"
#include "opendoor.h"
#include "rest.h"
#include "shoot.h"
#include "vec.h"

namespace Heros {

std::unordered_map<std::string, Reaction> key_bindings = {
    {"Left",
     []() {
         return std::make_unique<Move>(Vec{-1, 0});
     }},
    {"Right",
     []() {
         return std::make_unique<Move>(Vec{1, 0});
     }},
    {"Up",
     []() {
         return std::make_unique<Move>(Vec{0, 1});
     }},
    {"Down",
     []() {
         return std::make_unique<Move>(Vec{0, -1});
     }},
    {"R", []() { return std::make_unique<Rest>(); }},
    {"C", []() { return std::make_unique<CloseDoor>(); }},
    {"E", []() { return std::make_unique<Shoot>(3); }}};

constexpr int default_speed{8};
const HeroType august{"dragon", default_speed, 10, std::make_shared<Bow>(3),
                      key_bindings};
}  // namespace Heros
