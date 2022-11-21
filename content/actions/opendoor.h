#pragma once

#include "action.h"

class OpenDoor : public Action {
public:
    Result perform(Engine& engine) override;

private:
};