#include <bits/stdc++.h>
using namespace std;

class FlyableBirds {
    public:
    virtual void fly(){}
    virtual void speak(){}
};

class NonFlyableBirds {
    public:
    virtual void speak(){}
};

class Sparrow : public FlyableBirds {
    public:
    void fly() override {
        cout << "Sparrow is Flying." << endl;
    }
    void speak() override {
        cout << "Sparrow is speaking" << endl;
    }
};

class Penguin : public NonFlyableBirds {
    public:
    void speak() override {
        cout << "Penguin is Speaking" << endl;
    }
};

int main() {

    FlyableBirds *sp = new Sparrow();
    sp->fly();
    sp->speak();
    
    NonFlyableBirds* pg = new Penguin();
    pg->speak();
    
    

    return 0;
}