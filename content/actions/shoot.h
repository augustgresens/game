#pragma once
#include "action.h"
#include "vec.h"

class Shoot : public Action {
public:
    Shoot(int damage);
    Result perform(Engine& engine) override;

private:
    Vec direction;
    Vec starting_position;
    Vec new_position;
    Vec ending_position;
    bool open_tile = true;
    double distance;
    int damage;
};