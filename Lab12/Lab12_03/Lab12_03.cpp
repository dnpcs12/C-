// Lab12_03.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class CStudent {
private:
	string m_Name;
	int  m_Number;
	string m_Major;

public:
	CStudent() {
		m_Name = "default";
		m_Number = 0;
		m_Major = "default";
	}
	~CStudent(){}
	void setName(string n) {
		m_Name = n;
	}
	string getName() {
		return m_Name;
	}
	
	void setNumber(int n) {
		m_Number = n;
	}
	int getNumber() {
		return m_Number;
	}

	void setMajor(string n) {
		m_Major = n;
	}
	string getMajor() {
		return m_Major;
	}

	void Display() {
		cout << "이름 : " << m_Name << "\n";
		cout << "학번 : " << m_Number << "\n";
		cout << "전공 : " << m_Major << "\n\n";
	}
};

class FileNotFoundException : public exception {
	string message;
public:
	FileNotFoundException(const string& fname):
		message("File \"" + fname + "\" not found" ){}
	virtual const char* what() const throw() {
		return message.c_str();
	}
};

vector<CStudent> read_file(string& filename) {
	ifstream fin(filename);
	if (fin.good()) {
		vector<CStudent> result;
		CStudent temp;
		string name;
		int num;
		string major;
		while (!fin.eof()) {
			fin >> name >> num >> major;
			temp.setName(name);
			temp.setMajor(major);
			temp.setNumber(num);
			result.push_back(temp);
		}
		return result;
	}
	else {
		throw FileNotFoundException(filename);
	}
}

int main()
{
	string str;



	cout << "파일 이름 : ";
	cin >> str;

	try {
		vector<CStudent> numbers = read_file(str);
		for (CStudent value : numbers)
			value.Display();
	}
	catch (std::exception& e) {
		cout << e.what() << '\n';
	}

    return 0;
}

