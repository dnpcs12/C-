// Lab04_04.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string sen1, sen2;

	ifstream input1,input2;
	ofstream comtext;

	input1.open("input1.txt");
	input2.open("input2.txt");
	comtext.open ("lab04_04.txt");
	while (getline(input1, sen1)) {
		comtext << sen1 << "\n";
	}
	
	comtext << "\n";
	while (getline(input2, sen2)) {
	comtext << sen2 << "\n";
	}
	input1.close();
	input2.close();
	comtext.close();

	

	
    return 0;
}

