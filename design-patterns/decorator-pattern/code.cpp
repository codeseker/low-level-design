#include <bits/stdc++.h>
using namespace std;

/*
    Usecases: 
        Text Editor: Text Bold, Italics and so on
        Logging: Basis, Timestamp, File and so on
        Billing System: Base Item: Coffee, addsOn are decorators, Milk, Whipped cream and so on
*/


// Component
class ICharacter {
    public:
    virtual string getAbility() = 0;
};

class Mario : public ICharacter {
    public:
    string getAbility() override {
        return "Mario Character";
    }
};

// Decorator
class IDecorator : public ICharacter {
    protected:
    ICharacter* ch;
    public:
    IDecorator(ICharacter* ch) {
        this->ch = ch;
    }
};

class HeightUpDecorator : public IDecorator {
    public:
    HeightUpDecorator(ICharacter* ch) : IDecorator(ch) {}
    
    string getAbility() override {
        return ch->getAbility() + " With HeightUp Power";
    }
};

class ShootingDecorator : public IDecorator {
    public: 
    ShootingDecorator(ICharacter* ch) : IDecorator(ch) {}
    string getAbility() override {
        return ch->getAbility() + " With Shooting Power";
    }
};

class FlyingDecorator : public IDecorator {
    public:
    FlyingDecorator(ICharacter* ch) : IDecorator(ch) {}

    string getAbility() override {
        return ch->getAbility() + " With Flying Power";
    }
};

int main() {

    ICharacter* mario = new FlyingDecorator(new ShootingDecorator(new HeightUpDecorator(new Mario())));
    cout << mario->getAbility() << endl;

    return 0;
}