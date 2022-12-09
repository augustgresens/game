#include "rest.h"

#include "actor.h"

Result Rest::perform(Engine&) {
    actor->take_damage(-1);
    return success();
}
