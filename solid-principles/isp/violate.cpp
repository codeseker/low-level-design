#include <bits/stdc++.h>
using namespace std;

// one bulky interface needs to be separated to acheive ISP
class Shape {
public:
	virtual void setDimension(int w, int h) {}
	virtual int getArea() {}
	virtual int getVolume() {}
};

class Square : public Shape {
	int width, height;
public:
	void setDimension(int w, int h) override {
		width = w;
		height = h;
	}
	int getArea() override {
		cout << "Area of Square: " << width*height << endl;
	}
	int getVolume() override {
		cout << "This shape do not have volume" << endl;
	}
};

class Rectangle : public Shape {
	int width, height;
public:
	void setDimension(int w, int h) override {
		width = w;
		height = h;
	}
	int getArea() override {
		cout << "Area of Rectangle: " << width*height << endl;
	} int getVolume() override {
		cout << "This shape do not have volume" << endl;
	}
};

class Cube : public Shape {
	int width, height;
public:
	void setDimension(int w, int h) override {
		width = w;
		height = h;
	}
	int getArea() override {
		cout << "Area of Cube: " << (6 * width * height) << endl;
	}

	// this shape required volume too, so we add a volume method in shape interface
	int getVolume() override {
		cout << "Volume of Cube: " << (width * width * width) << endl;
	}
};

int main() {

    Shape * sq = new Square();
    Shape * rc = new Rectangle();
    Shape * cube = new Cube();

    sq->setDimension(10, 10);
    sq->getArea();
    sq->getVolume(); // this breaks LSP first thing 

    rc->setDimension(5, 5);
    rc->getArea();

    cube->setDimension(2, 2);
    cube->getArea();
    cube->getVolume();


	return 0;
}