// Lab06_02.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


class CStudent {
	int number;
	string name;
	string major;
public:
	CStudent() {
		number = 2018000000;
		name = "홍길동";
		major = "컴퓨터공학과";
	}

	CStudent(int stu_id, string stu_name, string stu_major) :
		number(stu_id), name(stu_name), major(stu_major) {
	}
	void Display() {
		cout << "학번 :" << number << endl;
		cout << "이름 :" << name << endl;
		cout << "전공 :" << major << endl;
		cout << endl;
	}
	void setNumber(int id) {
		number = id;
	}
	void setName(string stu_name) {
		name = stu_name;
	}
	void setMajor(string stu_major) {
		major = stu_major;
	}
	int getNumber() {
		return number;
	}
	string getName() {
		return name;
	}
	string getMajor() {
		return major;
	}
};

bool isprimary(CStudent stu[], int id) {
	bool check = true;
	for (int i = 0;i < 3;i++) {
		if (stu[i].getNumber() == id) {
			check = false;
			break;
		}
	}
	return check;
	
}

int main()
{
	CStudent s[3];
	int inputNumber;
	string inputName, inputMajor;
	int length = 0;

	while (1) {
		cout << "학번 : "; cin >> inputNumber;
		cout << "이름 : "; cin >> inputName;
		cout << "전공 : "; cin >> inputMajor;
		if (isprimary(s, inputNumber)) {
			s[length].setNumber(inputNumber);
			s[length].setName(inputName);
			s[length].setMajor(inputMajor);
			length++;
			cout << "※입력 완료\n\n";
		} 
		else {
			cout << "※중복된 학번이 존재합니다.\n";
		}
		if (length == 3) {
			cout << "----모든 입력이 완료되었습니다----\n";
			for (int i = 0; i < 3; i++) {
				cout << i+1 << "학생정보\n";
				s[i].Display();
			}
			break;
		}
	}
    return 0;
}

