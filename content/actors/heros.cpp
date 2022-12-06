#include "hero.h"

void Hero::attack(Actor& defender) {
    type.weapon->use(engine, *this, defender);
}