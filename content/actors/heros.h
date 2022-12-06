#pragma once

#include "bow.h"
#include "closedoor.h"
#include "herotype.h"
#include "move.h"
#include "none.h"
#include "opendoor.h"
#include "rest.h"

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
    {"C", []() { return std::make_unique<CloseDoor>(); }}};

constexpr int default_speed{8};
const HeroType necromancer{"necromancer", default_speed, 10,
                           std::make_shared<Bow>(2), key_bindings};
}  // namespace Heros
