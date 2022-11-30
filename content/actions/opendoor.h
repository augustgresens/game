#pragma once

#include "action.h"

class OpenDoor : public Action {
public:
    // OpenDoor(position);
    Result perform(Engine& engine) override;
};