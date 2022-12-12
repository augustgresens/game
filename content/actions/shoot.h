#pragma once
#include "action.h"
#include "sprite.h"
#include "vec.h"

class Shoot : public Action {
public:
    Result perform(Engine& engine) override;

private:
    Vec direction;
    Vec starting_position;
    Vec new_position;
    Vec ending_position;
    bool open_tile;
    double distance;
    int damage;
    Sprite arrow;
};