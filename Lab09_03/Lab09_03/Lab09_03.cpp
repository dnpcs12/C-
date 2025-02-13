// Lab09_03.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include<cstdlib>

using namespace std;

bool rangeCheck(int n) {
	if (n < 10 && n > 0) {
		return true;
	}
	else return false;
}

int startGame(int input[],int answer[]) {
	int round = 1;

	while (round < 10) {
		
		cout << "======================="<<round<<"========================\n";

		
		while (1) {
			bool check = true;
			cout << "1~9 범위의 숫자 세 개를 입력해주세요 : ";  
			for (int i = 0; i < 3; i++) {
				cin >> input[i];
				if (!rangeCheck(input[i])) {
					check = false;
				}
				for (int j = 0; j < i; j++) {
					if (input[i] == input[j]) check = false;
				}
			}
			if (check) break;
		}


		int strike = 0;
		int ball = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (input[i] == answer[j]) {
					if (i == j) {
						strike++;
					}
					else {
						ball++;
					}
				}
			}
		}
		if (strike == 0 && ball == 0) {
			cout << "out!!\n";
		}
		else {
			cout << strike << " Strike, " << "   " << ball << " Ball\n";
		}
		if (strike == 3) {
			cout << "정답입니다!\n";
			break;
		}
		round++;
	}
	if(round  > 9){
		cout << "패배했습니다. ";
		cout << "정답은 " << answer[0]<< ' ' << answer[1] << ' ' << answer[2] << "입니다."; 
	}
	return 0; 
}



int main()
{
	srand((unsigned int)time(NULL));
	int input[3];
	int answer[3] = { 0,0,0 };

	
	int random = 0;
	
	for(int i = 0; i <3; i ++){
		
		while(1) {
			bool check = false;
			random = (rand() % 9) + 1;
			for (int k = 0; k < i; k++) {
				if (answer[k] == random) {
					check = true;
					break;
				}
			}
			if (!check) {
				answer[i] = random;
				break;
			}
			
		}
	
	}

	startGame(input, answer);


	
    return 0;
}

