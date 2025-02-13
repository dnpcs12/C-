// Lab07_03.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
class Account {
private:
	string name;
	string id;
	int balance;
public:
	Account():name("defalut"),id("defalut"),balance(0){}

	Account(string cus_name, string cus_id, int cus_balance) {
		name = cus_name;
		id = cus_id;
		balance = cus_balance;
	}
	void setName(string cus_name) {
		name = cus_name;
	}
	void setId(string cus_id){
		id = cus_id;
	}
	void setBalance(int cus_bal){
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
};

std::ostream& operator<<(std::ostream& os, Account ac) {
	return os << "학번 :" << ac.getId() << "    이름: " << ac.getName() << "    잔액 : " << ac.getBal() << "\n";
}

int checkId(Account ac[], string put_id) {
	for (int i = 0; i < 3; i++) {
		if(ac[i].getId() == put_id)
		return i;
	}
	return -1;
}
void sendMoney(Account& send, Account& get) {
	get + send;
	send - send;
}


int main()
{
	Account acnt[3] = { Account("신은섭","2015",10000),  //2019204212
		Account("김유민","2012",0),//2012311060
		Account("이강호","2011",5000) };//2011102214
	
	string send_id = " ";
	string get_id = " ";
	int send_num, get_num = -1;
	
	while (1) {

		cout << "돈을 보낼 학생의 학번을 입력하세요:"; cin >> send_id;
		if (send_id == "종료") {
			break;
		}
		cout << "돈을 받을 학생의 학번을 입력하세요:"; cin >> get_id;
		if (send_id == get_id) {
			cout << "보내는 학생과 받는 학생의 학번이 동일합니다. 다시 입력해주세요.\n";
			continue;
		}
		send_num = checkId(acnt, send_id);
		get_num = checkId(acnt, get_id);
		if (send_num == -1 || get_num == -1) {
			cout << "보내는 학생 혹은 받을 학생의 학번이 존재하지 않습니다. 다시 입력해주세요.\n";
			continue;
		}
		if (acnt[send_num].getBal() == 0) {
			cout << "보내는 학생의 잔액이 부족합니다.\n";
			continue;
		}
		sendMoney(acnt[send_num], acnt[get_num]);

		cout << "보낸 학생의 잔액 : " << acnt[send_num];
		cout << "받은 학생의 잔액 : " << acnt[get_num];

	}
	cout << "종료합니다.\n";
	for (int i = 0; i < 3; i++) {
		cout << acnt[i];
	}
	
    return 0;
}

