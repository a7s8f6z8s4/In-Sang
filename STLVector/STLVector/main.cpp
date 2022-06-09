#include <iostream>
#include <vector>

using namespace std;



int main(void)
{
	vector<int> vecNumbers;
//	데이터 타입	데이터 이름	(지역변수)

	for (int i = 0; i < 10; i++)
		vecNumbers.push_back(10 * i);

	for (vector<int>::iterator iter = vecNumbers.begin(); iter != vecNumbers.end(); ++iter)
	{
		cout << (*iter) << endl;
	}


	// 반환하려고 하는 데이터 타입과 내가 사용하려는 데이터 타입이 같아야 사용이 가능하다.
	// 데이터의 변형이 생길 수 있다.
	/*
	int Array[16];

	for (int i = 1; i < 17; i++)
		Array[i + (-1)] = i;

	int* iterator = Array;

	for (int i = 0; i < 16; i++)
		cout << Array[i] << endl;		<- 직접접근

	for (int i = 0; i < 16; i++)
		cout << *(iterator + i) << endl;	<- 간접접근
		cout << *(iterator++) << endl;
	*/

	return 0;
}


// ** char가 1byte가 된 이유: 최초의 컴퓨터 ENIAC은 문자를 나타내기 위해 만들어진 컴퓨터
// ** char 의 표현범위: -128 ~ 127 까지 [표현갯수: 256개]
// ** short 의 표현범위: -32,768 ~ 32,767 까지 [표현갯수: 65,536개] 4byte
// ** int 의 표현범위: -32,768 ~ 32,767 까지 [표현갯수: 65,536개] 4byte
// ** int는 16bit 컴퓨터에서는 16bit로, 32bit 컴퓨터에서는 32bit로 만들어준다. 아마 그 때 당시에 중간 과정이 필요할 것 같다.
// ** long 의 표현범위: -2,147,483,648 ~ 2,147,483,647 까지 [표현갯수: 4,294,967,296개] 8byte

// ** stack 구조는 순차적으로 함수를 실행한다

// ** 나는 반드시 원본 데이터의 값을 가져와야 된다 -> Call by Reference
// ** 나는 그냥 데이터 값을 받아와서 처리할거다 -> Call by Value

/*
	{
		int* Pointer = new int;
		// ** 이 함수는 stack이다
	}

	// Pointer 이 친구는 사용 불가능
*/

// 간접접근
// ** 배열 말고는 직접접근할 수 있는 녀석이 불가능하기 때문에 사용한다
// ** 데이터 관리, 포인터 (배열도 결국은 포인터)
