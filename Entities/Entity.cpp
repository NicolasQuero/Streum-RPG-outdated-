#include <iostream>
#include "Pos.h"
#include "Entity.h"

Entity::Entity(char type, int x, int y, int hp, int dmg) : type(type), hp(hp), dmg(dmg), pos(x, y), is_alive(true) {
    cout << getType() << " type | " << this->getHp() << " HP" << endl;
}

Entity::Entity(char type, Pos p, int hp, int dmg) : type(type), pos(p), hp(hp), dmg(dmg), is_alive(true) {}

bool Entity::attack(Entity &E) {
    E.inflictDamage(dmg);
    cout << this->type << " inflige " << this->dmg << " point(s) de dégâts à " << E.type << endl;
    cout << E.type << " n'a plus que " << E.hp << " points de vie !" << endl;
    return E.isAlive();
}
