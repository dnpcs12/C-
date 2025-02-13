// Lab08_01.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//


#include "stdafx.h"
#include <iostream>

using namespace std;

class Polygon{
public:
	Polygon() :mPoint(0), mLength(0) {};
	Polygon(int point, float length) :mPoint(point), mLength(length) {};
	~Polygon() {};
	virtual void calcGirth() {
		cout << "Girth: ";
		cout << "empty\n";
		

	};
	virtual void calcArea() {
		cout << "Area: ";
		cout << "empty\n";
	
		
	};

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
		cout << "Girth:";
		cout << mPoint * mLength << endl;
	}
	void calcArea() override {
		cout << "Area:";
		cout << mLength * mLength << endl;
		
	};
};


int main()
{
	Polygon pol;
	Rectangle rec(4, 10);

	cout << "---Polygon class ----" << endl;
	pol.calcGirth();
	pol.calcArea();
	cout << "---Rectangle class---" << endl;
	rec.calcGirth();
	rec.calcArea();


    return 0;
}

