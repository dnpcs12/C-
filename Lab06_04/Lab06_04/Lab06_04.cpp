// Lab06_04.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
	string name,major;
	int id;
	vector <string>subject;
	vector <char>grade;

public:
	Student() :
		name("default"), id(0), major("depart") {}
	Student(string stu_name, int stu_id, string stu_major) {
		name = stu_name;
		id = stu_id;
		major = stu_major;
	}
	
	void setName(string stu_name) {
		name = stu_name;
	}
	void setID(int stu_id) {
		id = stu_id;
	}
	void setdept(string dept) {
		major = dept;
	}
	void print() {
		cout << name << " " << id << " " << major << '\n';
	}
	void addGrade(string sub, char stu_grade) {
		subject.push_back(sub);
		grade.push_back(stu_grade);
	}
	void printGrades() {
		for (int i = 0; i < subject.size(); i++) {
			cout << subject[i] << " " << grade[i]<< '\n';

		}
		cout << "GPA: "<< getGPA() << '\n';

	}
	float getGPA() {
		float gpa = 0;
		
		for (int i = 0; i < grade.size(); i++) {
			switch (grade[i])
			{
			case 'A':
				gpa = gpa + 4;
				break;
			case 'B':
				gpa = gpa + 3;
				break;
			case 'C':
				gpa = gpa + 2;
				break;
			case 'D':
				gpa = gpa + 1;
				break;
			case 'F':
				break;
			default:
				break;
			}
		}
		gpa = gpa / grade.size();
		return gpa;
	}
	void getYear(int year) {
		//2018102134
		//   1000000
		
		year = year - id / 1000000;
		switch (year)
		{
		case 0:
			cout << "Freshmen(1학년)\n";
			break;
		case 1:
			cout << "Sophmore(2학년)\n";
			break;
		case 2:
			cout << "Junior(3학년)\n";
			break;
		case 3:
			cout << "Senior(1학년)\n";
			break;
		default:
			cout << "About to graduate(5학년)\n";
			break;
		}
	}

};


int main()
{
	Student Harry("Harry", 2017310973, "CS");
	Harry.print();
	Harry.getYear(2019);
	Harry.addGrade("programming", 'A');
	Harry.addGrade("Basic Circuit", 'B');
	Harry.printGrades();
	cout << "\n\n";

	Student ron;
	ron.print();
	cout << '\n';
	ron.setName("Ron");
	ron.setID(2014103959);
	ron.setdept("EE");
	ron.print();
	ron.getYear(2019);
	ron.addGrade("Computer Architecture", 'B');
	ron.addGrade("Maching Learning", 'B');
	ron.addGrade("Computer Vision", 'C');
	ron.printGrades();

    return 0;
}

