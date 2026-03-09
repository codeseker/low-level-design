#include <bits/stdc++.h>
using namespace std;

class WeaponBehavior {
    public:
    virtual void useWeapon() = 0;
};

class KnifeBehavior : public WeaponBehavior {
    public:
    void useWeapon() override {
        cout << "Using Knife" << endl;
    }
};

class AxeBehavior : public WeaponBehavior {
    public:
    void useWeapon() override {
        cout << "Using Axe" << endl;
    }
};

class SwordBehavior : public WeaponBehavior {
    public:
    void useWeapon() override {
        cout << "Using Sword" << endl;
    }
};

class BowAndArrowBehavior : public WeaponBehavior {
    public:
    void useWeapon() override {
        cout << "Using Bow and Arrow" << endl;
    }
};

class Character {
    public:
    WeaponBehavior * weapon;

    virtual void fight() = 0;

    void setWeapon(WeaponBehavior * weapon) {
        this->weapon = weapon;
    }
};

class Knight : public Character {
    public:

    void fight() override {
        cout << "Knight is Fighting" << endl;
        weapon->useWeapon();
    }
};

class King : public Character {
    public:

    void fight() override {
        cout << "King is Fighting" << endl;
        weapon->useWeapon();
    }
};

class Trail : public Character {
    public:

    void fight() override {
        cout << "Trail is Fighting" << endl;
        weapon->useWeapon();
    }
};

class Queen : public Character {
    public:

    void fight() override {
        cout << "Queen is Fighting" << endl;
        weapon->useWeapon();
    }
};


int main() {
    Character* king = new King();

    WeaponBehavior* wp = new SwordBehavior();
    king->setWeapon(wp);

    king->fight();
}
