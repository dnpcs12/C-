// Lab08_02.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;
class Polygon {
public:
	Polygon() :mPoint(0), mLength(0) {};
	Polygon(int point, float length) :mPoint(point), mLength(length) {};
	~Polygon() {};
	virtual void calcGirth() {
		cout << "Girth: empty \n";
	}
	virtual void calcArea() {
		cout << "Area: empty\n";

	}

protected:
	int mPoint;
	double mLength;
};


class Rectangle : public Polygon {
public:
	Rectangle() {};
	Rectangle(int point, float length) :Polygon(point, length) {};
	~Rectangle() {};
	void calcGirth() override {
		cout << "Girth: " << mLength * mPoint << endl;
		
	}
	void calcArea() {
		cout << "Area: ";
		cout << mLength * mLength << endl;
	}
};
class Triangle:public Polygon {
public:
	Triangle() :Polygon() {};
	Triangle(int point, float length) :Polygon(point, length) {};
	void calcGirth() override {
		cout << "Girth: " << mLength * mPoint << endl;

	}
	void calcArea() override {
		cout << "Area: ";
		cout << (mLength * (mLength/2 * sqrt(3))) /2   << endl;
	}

};
class Circle:public Polygon{
public:
	Circle() {};
	Circle(int point, float length) :Polygon(point, length) {};

	void calcGirth() override {
		cout << "Girth: " << mLength * 2 * 3.14 << endl;

	}
	void calcArea() override{
		cout << "Area: ";
		cout << mLength * mLength * 3.14 << endl;
	}
	

};

int main()
{
	Triangle tri(3, 10);
	Rectangle rec(4, 10);
	Circle cir(0, 5);
	
	cout << "--- Triangle class ---" << endl;
	tri.calcGirth();
	tri.calcArea();
	cout << "--- Rectangle class ---" << endl;
	rec.calcGirth();
	rec.calcArea();
	cout << "--- Circle class ---" << endl;
	cir.calcGirth();
	cir.calcArea();

    return 0;
}

