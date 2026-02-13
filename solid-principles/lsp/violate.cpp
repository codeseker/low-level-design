#include <bits/stdc++.h>
using namespace std;


class Bird {
    public:
    virtual void fly() {}
    virtual void speak(){}
};

class Sparrow : public Bird {
    public:
    void fly() override {
        cout << "Sapprow is FLying now" << endl;
    }
    void speak() override {
        cout << "Sparrow is speaking now" << endl;
    }
};

class Penguin : public Bird {
    public:
    void fly() override {
        cout << "Penguin Cannot Fly." << endl;
    }
    void speak() override {
        cout << "Penguin is speaking now" << endl;
    }
};

int main() {

    
    Bird * sp = new Sparrow();
    Bird * pg = new Penguin();

    sp->fly();
    sp->speak();

    // This penguin class is narrowing the properties of Bird class as this cannot fly, breaking LSP here.
    pg->fly();
    pg->speak();

    return 0;
}