#include <bits/stdc++.h>
using namespace std;

class Shape2D {
public:
	virtual void setDimension(int w, int h) {}
	virtual int getArea() {}
};

class Shape3D {
public:
	virtual void setDimension(int w, int h) {}
	virtual int getArea() {}
    virtual int getVolume() {}
};

class Square : public Shape2D {
	int width, height;
public:
	void setDimension(int w, int h) override {
		width = w;
		height = h;
	}
	int getArea() override {
		cout << "Area of Square: " << width*height << endl;
	}
};

class Rectangle : public Shape2D {
	int width, height;
public:
	void setDimension(int w, int h) override {
		width = w;
		height = h;
	}
	int getArea() override {
		cout << "Area of Rectangle: " << width*height << endl;
	}
};

class Cube : public Shape3D {
	int width, height;
public:
	void setDimension(int w, int h) override {
		width = w;
		height = h;
	}
	int getArea() override {
		cout << "Area of Cube: " << (6 * width * height) << endl;
	}

	int getVolume() override {
		cout << "Volume of Cube: " << (width * width * width) << endl;
	}
};

int main() {

    Shape2D * sq = new Square();
    Shape2D * rc = new Rectangle();
    Shape3D * cube = new Cube();

    sq->setDimension(10, 10);
    sq->getArea();

    rc->setDimension(5, 5);
    rc->getArea();

    cube->setDimension(2, 2);
    cube->getArea();
    cube->getVolume();


	return 0;
}