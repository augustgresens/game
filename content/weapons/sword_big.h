#pragma once
#include "engine.h"
#include "weapon.h"

class BigSword : public Weapon {
public:
    BigSword(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};