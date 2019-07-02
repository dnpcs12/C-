// LN13_2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
//출처 : https://z-man.tistory.com/207 [지맨네집]}
//수정 : kiokahn@daum.net 

#include <iostream>
#include <vector>
#include <algorithm> 
#include <functional>

using namespace std;


int main()
{
	// 람다의 구성
	// [capture] (parameters) -> returnType { statement }
	//함수 원형이 있을 뿐 실행 되지 않음
	[](int i)->int { 
		return i + 1; 
	};

	//함수를 호출하여 실행
	[](int i)->int {
		return i + 1;
	}(2);

	// 만약 외부 변수를 람다에 넘기고 싶다면..
	int k = 10;
	[k](int i)->int { 
		return i + k; 
	};

	[k](int i)->int {
		return i + k;
	}(3);

	// 리턴 타입과 파라메터등은 필요 없으면 안써줘도 된다. 그러나 [] 반드시 필요함!
	[] {
		cout<<"Hello"<<endl; 
	}; // include iostream

	[] {
		cout << "Hello" << endl;
	}(); // include iostream

	// 람다는 변수에 담을수도 있다
	auto Func1 = [] {
		printf("Hello\n"); 
	};
	Func1();

	// 그 외에 [] 를 사용할때
	// 1. [&](){}... call-by-reference (외부의 모든 변수를 가져옴)
	// 2. [=](){}... call-by-value (외부의 모든 변수를 가져옴)
	// 3. [=, &x, &y](){} (외부의 모든 변수를 가져오는것 동일하지만 그 중 x와 y는 reference로 가져온다)

	// call-by-value 테스트
	int A = 10;
	int B = 20;
	// auto Func2 = [=](){A=30; printf("%d\n", A);};
	// Func2();
	// 이렇게 빌드하면 에러메세지로 'A': a by-value capture cannot be modified in a non-mutable lambda 라고 에러 메시지가 뜬다.
	auto Func3 = [&]() {
		A = 30; 
		printf("%d\n", A); 
	};

	Func3();
	printf("%d\n", A);

	// 배열 초기화
	vector<int> Arr; // include vector
	auto InitArr = [&Arr]() {
		for (int i = 0; i < 10; ++i) {
			Arr.push_back(i);
		}
	};
	InitArr();
	// 출력
	for_each(Arr.begin(), Arr.end(), [](int i) { printf("%d\n", i); }); // include algorithm

	// auto를 사용하면 타입이 정확하지 않지만 function 을 사용하면 타입이 명확해지므로 여러가지 가능하다.
	function<int(char)> f; // include functional
	f = [](char a)->int { printf("%c\n", a); return 30; };
	int ReturnValue = f('A');
	printf("%d\n", ReturnValue);

	// 그렇다면?? 예제1
	typedef function<char(int)> LF;
	vector<LF> VF;

	char ARR[] = "ABCDEFGHIJKLMNOP";
	for (int i = 0; i < 10; ++i) {
		LF A = f;
		VF.push_back(A);
	}

	for (int i = 0; i < 10; ++i) {
		VF[i](ARR[i]);
	}

	// 예제2
	function<int(int)> fact;
	fact = [&fact](int n)->int { if (n == 0) { return 1; } else { return (n * fact(n - 1)); } };
	printf("fact(10) : %d\n", fact(10));


	// 이런식으로도 가능함.. 특수문자 에러나서 () 로 치환했음 ;;; 
	// typedef hash_map(KEY, Room*) MazeRoom;
	// MazeRoom _room;
	// for_each( _room.begin(), _room.end(), [](std::pair(KEY, Room*) r){ delete r.second; });

	// 이렇게 람다를 사용하면 런타임시 클로져(Closure)객체가 생성 된다.
	// 이름은 없지만 메모리 상에 임시적으로 존재한다.
	// 클로져는 FunctionObject처럼 행동하고 이러한 연유로 람다를 람다 함수라고도 하는데, 클로져객체라 불러야한다!!
	return 0;
}


