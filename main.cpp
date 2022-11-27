#include "engine.h"
#include "heros.h"

int main() {
    std::string filename{"settings.txt"};
    Settings settings = read_settings(filename);
    Engine engine{settings};

    engine.create_hero(Heros::necromancer);
    for (int i = 0; i < 20; ++i) {
        engine.create_monster(MonsterType::goblin);
    }
    engine.run();
}
