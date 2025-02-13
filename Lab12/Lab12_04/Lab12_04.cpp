// Lab12_04.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

class FileNotFoundException : public exception {
	string message;
public:
	FileNotFoundException(const string& fname) :
		message("File \"" + fname + "\" not found") {}
	virtual const char* what() const throw() {
		return message.c_str();
	}
};

void writefile() {
	ofstream fin("temp.txt");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			fin << rand() % 100 << " ";
		}
		fin << "\n";
	}
	fin.close();
}

vector<vector <int>> read_file(string& filename) {
	ifstream fin(filename);
	if (fin.good()) {
		vector<vector <int>> result(10,vector<int>(10));
		int temp;
		for(int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++) {
				fin >> temp;
				result[i][j] = temp;
			}
		}
		return result;
	}
	else {
		throw FileNotFoundException(filename);
	}
}


int main()
{
	srand((unsigned int)time(NULL));
	string str;
	vector <vector <int>> list;
	writefile();
	cout << "파일 이름 : "; cin >> str;


	try {
		    list = read_file(str);
			int row, col;
			cout << "출력할 행 크기: "; cin >> row;
			cout << "출력할 열 크기 : "; cin >> col;
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					cout << list.at(i).at(j) << " ";
				}
				cout << "\n";
			}
		
	}
	catch (exception& e) {
		cout << "\n" << e.what() << '\n';
	}
    return 0;
}

