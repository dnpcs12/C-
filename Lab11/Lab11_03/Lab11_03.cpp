// Lab11_03.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//(홀수)마방진 그리기 프로그램. 

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Mabangjin{
private:
	vector<vector<int>> mabangjin;
	int m_size;
	int pX;
	int pY;
public:
	Mabangjin(int s) {
		m_size = s;
		for (int i = 0; i < s; i++) {
			mabangjin.push_back(vector<int>(s, -1));
		}
		pX = 0;
		pY = (s / 2);

	}
	//마방진을 만드는 함수
	void make() {
		int num = 1;
		mabangjin[pX][pY] = num;
		while(!isend(pX,pY)) {
			num++;
			//printPoint();
			move(pX, pY);
			mabangjin[pX][pY] = num;
			//printPoint();
			//print();
		}
	}
	// 다음 숫자가 써질 곳으로 움직임
	void move(int x, int y) {
		x = x - 1; y = y + 1; // 대각선 방향으로 위/ 오른쪽으로 이동.

		if (isout(x) && isout(y)) { // 이동한 곳의 x,y좌표가 모두 범위 밖이라면 원래 좌표의 아래로 이동
			x = pX + 1;
			y = pY;
		}
		else {
			if (isout(x)) { // 이동한 곳의 x좌표가 범위 밖이라면 맨 아래로 줄로 이동
				x = m_size - 1;
			}
			if (isout(y)) { // 이동한 곳의 y좌표가 범위 밖이라면, 맨 앞 칸으로 이동.
				y = 0;
			}
		}
	
		if (isfull(x, y)) { // 이동한 좌표에 이미 그렸다면, 원래 좌표의 아래로 이동
			x += 2;
			y -= 1;
		}

		pX = x; pY = y;
	}
	// 마방진이 다 그려졌는지 확인
	bool isend(int x, int y) {
		if (x == m_size - 1 && y == m_size / 2) return true;
		return false;
	}

	//현재 위치 출력
	void printPoint() {
		cout << "(" << pX << ", " << pY << ")" <<"\n";
	}

	//범위를 벗어났는지 확인
	bool isout(int n) {
		if (n < 0 || n >= m_size) return true;
		return false;
	}

	//현재 지점을 이미 그렸는지 확인.
	bool isfull(int x, int y) {
		if (mabangjin[x][y] != -1) return true;
		else return false;
	}

	//마방진 출력
	void print() {
		for (int i = 0; i < m_size; i++) {
			for (int j = 0; j < m_size; j++) {
				cout << setw(4)<< mabangjin[i][j] << setw(4);
			}
			cout << "\n";
		}
	}
};


int main()
{
	int odd = 0;

	cout << "홀수 숫자 하나를 입력해주세요: "; cin >> odd;
	Mabangjin m(odd);
	m.make();
	m.print();

    return 0;
}

