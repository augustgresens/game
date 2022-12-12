#pragma once
#include "engine.h"
#include "vec.h"
#include "weapon.h"

class Bow : public Weapon {
public:
    Bow(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;

private:
    Vec starting_position;
    Vec ending_position;
};