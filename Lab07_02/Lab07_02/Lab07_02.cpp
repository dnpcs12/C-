// Lab07_02.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
	int x, y;
public:
	Point() :x(0), y(0) {}

	Point(int ux, int uy) {
		x = ux;
		y = uy;
	}
	void setPoint(int ux, int uy) {
		x = ux;
		y = uy;
	}
	int getX() const {
		return x;
	}
	int getY() const{
		return y;
	}
	Point operator-(const Point&p);
	Point& operator=(const Point&p);
	Point operator*(const Point&p);

};

Point Point::operator*(const Point& p) {
	Point result(this->x * (p.getX()), this->y * (p.getY()));
	return result;
}
Point Point::operator-(const Point& p) {
	Point result(this->x - p.getX(), this->y - p.getY());
	return result;

}
Point &Point::operator=(const Point& p) {
	this->x = p.getX();
	this->y = p.getY();
	return *this;
}




int main()
{
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	Point *pP1, *pP2, *pP3;

	cout << "첫번째 좌표를 입력해주세요:"; cin >> x1 >> y1;
	cout << "두번째 좌표를 입력해주세요:"; cin >> x2 >> y2;
    
	pP1 = new Point(x1, y1);
	pP2 = new Point(x2, y2);
	pP3 = new Point();

	*pP3 = (*pP1 - *pP2) * (*pP1 - *pP2);
	double result = sqrt(pP3->getX() + pP3->getY());
	cout << " 두 좌표 사이의 길이는 " << result << "입니다." <<endl;

	delete pP1;
	delete pP2;
	delete pP3;

    return 0;
}

