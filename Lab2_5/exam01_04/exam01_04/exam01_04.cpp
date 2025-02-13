// exam01_04.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void get_user_input(string& input) {
	while (1) {
		cout << "User input (ROCK, PAPER, SCISSORS): "; cin >> input;
		if (input == "ROCK" || input == "PAPER" || input == "SCISSORS") break;
	}

}
void get_com_input(string& com_input) {
	int num = rand() % 3 ; 
	switch (num)
	{
	case(0): com_input = "ROCK";
		break;
	case(1): com_input = "PAPER";
		break;
	case(2): com_input = "SCISSORS";
		break;
	
	default:
		break;
	}
	cout << "Computer input: " << com_input << '\n';
}
void check_result(string user, string com) {
	if (user == com) {
		cout << "Draw";
	}
	else if (user == "ROCK" && com == "SCISSORS") {
		cout << "you win!";
	}
	else if (user == "ROCK" && com == "PAPER") {
		cout << "you lose";
	}
	else if (user == "SCISSORS" && com == "PAPER") {
		cout << "you win!";
	}
	else if (user == "SCISSORS" && com == "ROCK") {
		cout << "you lose";
	}
	else if (user == "PAPER" && com == "ROCK") {
		cout << "you win!";
	}
	else if (user == "PAPER" && com == "SCISSORS") {
		cout << "you lose";
	}
	cout << '\n';
}


int main()
{
	srand((unsigned int) time(NULL));
	string user_input, com_input;
	for (int i = 1; i <= 10; i++) {
		cout << i << "-th play..." << endl;
		get_user_input(user_input);
		get_com_input(com_input);
		check_result(user_input, com_input);
	}

    return 0;
}

