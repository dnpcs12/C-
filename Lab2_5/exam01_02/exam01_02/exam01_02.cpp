// exam01_02.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void lower(string& song) { // a = 97 , A = 65
	int i = 0;
	while (i <= song.length()) {
		if ((int)song[i] > 65 && (int)song[i] < 97) {
			song[i] = (int)song[i] + 32;
		}
		i++;
	}
}


void swapcase(string& song) { // a = 97 , A = 65
	int i = 0;
	while (i <= song.length()) {
		if ((int)song[i] > 65 &&(int)song[i] < 97) {
			song[i] = (int)song[i] + 32;
		}
		else if((int)song[i]>=97 && (int)song[i] <= 122){
			song[i] = (int)song[i] - 32;
	}
		i++;
	}
}

int find_string_num(string sen, string target) {
	int i = 0;
	int target_num = 0;
	while (1) {
		i = sen.find(target, i);
		if (i != string::npos) {
			target_num++;
			i++;
		}
		else break;
	}
	return target_num;
}

int main()
{
	ifstream song;
	ofstream output;
	string all;
	string line;
	int peace_num = 0;

	song.open("input.txt");
	output.open("output.txt");

	if (song.is_open()) {
		string line;

		while (getline(song, line)) {
		
			all = all + line;
			
			if (line[0] != '<' && !line.empty()) {
				swapcase(line);
				output << line << '\n';
			}
		}
	}
	lower(all);
	peace_num = find_string_num(all, "peace");

	song.close();
	output.close();

	cout << peace_num;
    return 0;
}

