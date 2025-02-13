// Lab11_04.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

template<typename T>
class Queue {
private:
	T *p_list;
	int size;
	int MAX_SIZE;
public:
	Queue(int _MAX_SIZE = 1000){
		MAX_SIZE = _MAX_SIZE;
		p_list = new T[_MAX_SIZE];
		size = 0;
	}
	
	~Queue() {
	   delete[] p_list;
	}
	
	int find_index(T _item) {
		for (int i = 0; i < size; i++) {
			if (_item == p_list[i]) return i;
		}
		return -1;
	}

	void Enqueue(T _item) {
		if (find_index(_item) == -1) {
			if (size >= MAX_SIZE) {
				cout << "out of memory";
			}
			else {
				p_list[size] = _item;
				size++;
			}
	
		}
	}
	T Dequeue() {
		T item = p_list[0];
		if (size == 0) {
			cout << "No item exsit in list\n";
		}
		else {
			for (int i = 1; i < size; i++) {
				p_list[i - 1] = p_list[i];
			}
			size--;
		}
		return item;
	}
	void print() const {
		cout << "Item in list : ";
		for (int i = 0; i < size; i++) {
			cout << p_list[i] << ", "; 
		}
		cout << "\n";
	}
	int get_size(){
		return size;
	}
	T get_item(int _index) {
		return p_list[_index];
	}
};

int main()
{
	Queue<int> int_queue;
	Queue<float>float_queue;
	Queue<char> char_queue;

	int_queue.Enqueue(1);
	int_queue.Enqueue(2);
	int_queue.Enqueue(2);
	int_queue.Enqueue(5);


	float_queue.Enqueue(4.3);
	float_queue.Enqueue(2.5);
	float_queue.Enqueue(3.7);
	float_queue.Enqueue(3.7);

	char_queue.Enqueue('b');
	char_queue.Enqueue('b');
	char_queue.Enqueue('c');
	char_queue.Enqueue('a');
	
	cout << "<Before Dequeye>" << endl;
	
	int_queue.print();
	float_queue.print();
	char_queue.print();

	int_queue.Dequeue();
	float_queue.Dequeue();
	float_queue.Dequeue();
	char_queue.Dequeue();
	char_queue.Dequeue();
	char_queue.Dequeue();
	char_queue.Dequeue();

	cout << "<Before Dequeye>" << endl;


	int_queue.print();
	float_queue.print();
	char_queue.print();

    return 0;
}

