#pragma once
#include "engine.h"
#include "weapon.h"

class Spear : public Weapon {
public:
    Spear(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};