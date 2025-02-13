// Lab08_04.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
/*어벤져스 배틀 
  사용자가 IronMan, CaptainAmerica, Thor 중 한 캐릭을 입력.
  컴퓨터가 임의로 세 캐릭중 하나를 선택.
  사용자와 컴퓨터 각각의 캐릭터 정보 출력.
  각 캐릭터별 공격력과 방어력 체력을 바탕으로 자동 배틀.(사용자가 선공)
  배틀 결과 출력. 
  */
#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;
class Avengers {
public:
	Avengers() {
		name = "";
		attack_point = 0;
		defense_point = 0;
		health = 0;
	}
	~Avengers(){}
	virtual void set(string _name, int _attack, int _defense, int _health) {
		name = _name;
		attack_point = _attack;
		defense_point = _defense;
		health = _health;
	}
	virtual int attack() {
		return 0;
	}
	virtual void defense(int _attack_point) {

	}
	virtual void print_info() {
		cout << "Name : " << name;
		cout << "\nAttack_point : " << attack_point;
		cout << "\ndefense_point : " << defense_point;
		cout << "\nhealth : " << health << "\n";
	}
protected:
	string name;
	int attack_point = 0;
	int defense_point = 0;
	int health = 0;
};

class Character : public Avengers {
public:
	int attack() override{
		return attack_point;
	}
	void defense(int _attack_point) override{
		health = health - (_attack_point -defense_point);
		if (health < 0) health = 0;
	}
	int get_health() {
		return health;
	}
};
int conversion(string name) {
	if (name == "IronMan") {
		return 0;
	}
	else if (name == "CaptainAmerica") {
		return 1;
	}
	else if (name == "Thor") {
		return 2;
	}
		
}
void setCharacter(Character& ch, int chracNum) {
	switch (chracNum)
	{
	case(0):
		ch.set("IronMan", 70, 40, 100);
		break;
	case(1):
		ch.set("CaptainAmerica", 60, 50, 100);
		break;
	case(2):
		ch.set("Thor", 80, 30, 100);
		break;
	default:

		break;
	}
}
int main()
{
	srand((unsigned int)time(NULL));

	Character my_char;
	Character enemy_char;
	string cName;
	int enemy = 0;
	bool myturn = true;


	cout << "Choose your character(IronMan, CaptainAmerica, Thor) : "; cin >> cName;
	enemy = rand() % 3;
	setCharacter(my_char, conversion(cName));
	setCharacter(enemy_char, enemy);
	cout << "--My Character--\n";
	my_char.print_info();
	cout << "--Enemy Character--\n";
	enemy_char.print_info();

	cout << endl << "--Battle--" << endl;
	cout << "My Life: " << my_char.get_health() << "\t"
		<< "Enemy Life : " << enemy_char.get_health() << endl;

	while (1) {
		if (myturn) {
			enemy_char.defense(my_char.attack());
			myturn = false;
		}
		else {
			my_char.defense(enemy_char.attack());
			myturn = true;
		}
		cout << "My Life: " << my_char.get_health() << "\t"
			<< "Enemy Life : " << enemy_char.get_health() << endl;
		if (enemy_char.get_health()== 0) {
			cout << "you win!\n";
			break;
		}
		else if(my_char.get_health() == 0) {
			cout << "you lose\n";
			break;
		}
	}

    return 0;
}

