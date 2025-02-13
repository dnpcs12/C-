// Lab07_04.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account {
private:
	string name;
	string id;
	int balance;
	static int all_balance;
public:
	Account() :name("defalut"), id("defalut"), balance(0) {}

	Account(string cus_name, string cus_id, int cus_balance) {
		name = cus_name;
		id = cus_id;
		balance = cus_balance;
	}
	void setName(string cus_name) {
		name = cus_name;
	}
	void setId(string cus_id) {
		id = cus_id;
	}
	void setBalance(int cus_bal) {
		balance = cus_bal;
	}
	string getName() {
		return name;
	}
	string getId() {
		return id;
	}
	int getBal() {
		return balance;
	}
	void operator+(Account ac) {
		balance = balance + ac.getBal();
	}
	void operator-(Account ac) {
		balance = balance - ac.getBal();
	}
	/*
	Account& operator=(Account& ac) {
	this->id = ac.getId();
	this->name = ac.getName();
	this->balance = ac.getBal();
	return *this;
	}
	}*/

	void operator=(Account ac) {
		name = ac.getName();
		id = ac.getId();
		balance = ac.getBal();
	}
	~Account() {
		all_balance = all_balance + balance;
	}
	int get_all_balance() {
		return all_balance;
	}
};
std::ostream& operator<<(ostream& os, Account ac) {
	return os << "학번 :" << ac.getId() << "    이름: " << ac.getName() << "    잔액 : " << ac.getBal() << "\n";
}

int Account::all_balance = 0;

bool isPrimary(Account ac[],string id,int count) {
	for (int i = 0; i < count; i++) {
		if (ac[i].getId() == id) {
			return false;
		}
	}
	return true;
}

int main()
{ 
  int size = 0;
  Account *acnt;

  string id, name = "";
  int balance = 0;
  cout << "총 학생의 수: "; cin >> size;

  acnt = new Account[size];

  bool isOverlap = false;

  for (int i = 0; i < size; i++) {
  cout << i + 1 << "번째 학생 계좌 입력: ";
  cout << "학번: "; cin >> id;
  if (!isPrimary(acnt, id, i)) {
  isOverlap = true;
  cout << "중복된 학번입니다.\n종료합니다.\n";
  break;
  };
  cout << "\n이름 : "; cin >> name;
  cout << "\n잔액 : "; cin >> balance;
  acnt[i].setId(id);
  acnt[i].setName(name);
  acnt[i].setBalance(balance);
  cout << "======================================\n";
  }

  delete[] acnt;

  if(!isOverlap)
  cout << "회수된 금액: " << Account().get_all_balance() << '\n';
  


	return 0;
}

