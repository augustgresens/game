#include "engine.h"
#include "heros.h"
#include "monsters.h"

int main() {
    std::string filename{"settings.txt"};
    Settings settings = read_settings(filename);
    Engine engine{settings};

    engine.create_hero(Heros::necromancer);
    for (int i = 0; i < 20; ++i) {
        engine.create_monster(Monsters::goblin());
        engine.create_monster(Monsters::orc_masked());
        engine.create_monster(Monsters::demon());
    }
    engine.run();

    // MonsterType new_monster_type = Monsters::goblin();
    // engine.create_monster(new_monster_type);
}
