// Lab10_03.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
template<typename T>



class CList {
public:
	CList() {
		for (int i = 0; i < 5; i++) {
			m_Array[i] = 0;
		}
		m_Length = 0;
	}
	~CList() {

	}
	bool IsPrimary(T data) {
		for (int i = 0; i < m_Length; i++) {
			if (m_Array[i] == data) return false;
		}
		return true;
	}
	bool IsEmpty() {
		if (m_Length == 0) return true;
		return false;
	}
	bool IsFull() {
		if (m_Length == 5) return true;
		return false;
	}
	void Add(T data) {
		if (IsFull()) {
			cout << "List is full\n";
		}
		else if (!IsPrimary(data)) {
			cout << "중복된 데이터가 존재합니다.\n";
		}
		else {
			m_Array[m_Length] = data;
			m_Length++;
			sort(data);
		}

	}
	void Delete(T data) {
		if (IsEmpty()) {
			cout << "List is empty\n";
		}
		else {
			for (int i = 0; i < m_Length; i++) {
				if (m_Array[i] == data) {
					for (int j = i; j < m_Length - 1; j++) {
						m_Array[j] = m_Array[j + 1];

					}
					m_Length--;
				}
			}
		}
	}
	void Print() {
		cout << "※ Current List\n";
		for (int i = 0; i < m_Length; i++) {
			cout << m_Array[i] << ' ';
		}
		cout << "\n";
	}
	void sort(int data) {
		for (int i = m_Length - 1; i >= 0 ; i--) {
			if (m_Array[i] > data) {
				int tep;
				tep = m_Array[i];
				m_Array[i] = data;
				m_Array[i+1] = tep;
			}
		}
	}

private:
	T m_Array[5];
	int m_Length;
};

int command() {
	int num;
	cout << "\n\t---- menu ----" << endl;
	cout << "\t1. 리스트 추가" << endl;
	cout << "\t2. 리스트 삭제" << endl;
	cout << "\t3. 리스트 출력" << endl;
	cout << "\t4. 프로그램 종료" << endl;
	cout << "\n\n입력 --> ";
	cin >> num;
	return num;
}

int main()
{
	CList<int> list;
	int input;
	int com;
	while (1) {
		com = command();

		switch (com)
		{
		case 1:
			cout << "\n추가할 데이터 : ";
			cin >> input;
			list.Add(input);
			break;
		case 2:
			cout << "\n삭제할 데이터 : ";
			cin >> input;
			list.Delete(input);
			break;
		case 3:
			list.Print();
			break;
		case 4:
			cout << "\n\t프로그램을 종료합니다.\n";
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}

