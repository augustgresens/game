#pragma once
#include "engine.h"
#include "weapon.h"

class Axe : public Weapon {
public:
    Axe(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};