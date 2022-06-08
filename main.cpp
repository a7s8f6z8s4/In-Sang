// ** Vector v0.9
#include <iostream>

using namespace std;

// ** 현재 원소의 개수
int Size = 0;

// ** 최대 수용 개수
int Capacity = 0;

// ** 컨테이너
int* Vector = nullptr;

// ** 컨테이너의 마지막 위치의 값을 추가.
void push_back(const int& _Value);

// ** 컨테이너의 마지막 위치의 값을 삭제.
void pop_back();

// ** 가장 앞 쪽에 있는 원소
int front();

// ** 가장 뒷 쪽에 있는 원소
int back();

// ** 특정 위치의 Value 삭제
void erase(const int _where);

// ** 특정 위치의 Value 추가
void Insert(const int& _where, const int& _Value);

int main(void)
{
	// ** 값 추가
	for (int i = 0; i < 10; ++i)
		push_back(i * 100 + 100);

	Insert(3, 300);

	cout << endl << Vector[2] << endl;

	for (int i = 0; i < Size; ++i)
	{
		cout << "Value: " << Vector[i] << endl;
	}

	return 0;
}

void push_back(const int& _Value)
{
	// ** 만약 더 이상 수용할 수 있는 공간이 없다면
	if (Capacity <= Size)
	{
		// ** 현재 수용량이 4보다 작다면 1씩 증가하고
		// ** 현재 수용량이 4보다 크거나 같다면 1/2 만큼 추가함
		Capacity += (Capacity <= 3) ? 1 : Capacity >> 1;

		// ** 임시 저장소 Temp 생성
		int* Temp = new int[Capacity];

		// ** 생성된 공간을 초기화
		for (int i = 0; i <= Capacity; i++)
			Temp[1] = NULL;

		// ** 기존에 있던 값을 복사
		for (int i = 0; i < Size; ++i)
			Temp[i] = Vector[i];

		// ** 기존의 값을 삭제
		if (Vector)
		{
			delete Vector;
			Vector = nullptr;
		}

		// ** 새로 할당 된 임시의 값(해당 주소)를 복사
		Temp[Size] = _Value;

		// ** 임시의 주소값에 복사 해둔 값과 추가된 새로운 값을 다시 전역변수로 저장되어 있는 Vector로 가져옴.
		Vector = Temp;
	}
	else
	{
		// ** 마지막 위치에 값 추가
		Vector[Size] = _Value;
	}

	// ** 현재 원소의 최대값 증가
	++Size;

}

void pop_back()
{
	--Size;
}

int front()
{
	// ** 0번째 원소 반환
	return Vector[0];
}

int back()
{
	// ** 마지막 원소 반환
	return Vector[Size - 1];
}

void erase(const int _where)
{
	// ** 현재 원소의 최대값 감소
	--Size;
	
	// ** 재정렬
	for (int i = _where + (-1); i < Size -1; i++)
	{
		Vector[i] = Vector[i + 1];
	}
}

void Insert(const int& _where, const int& _Value)
{
	if (Capacity <= Size)
		Capacity += (Capacity <= 3) ? 1 : Capacity >> 1;
	else
		Vector[Size] = _Value;

	// ** 임시 저장소 Temp
	int* Temp = new int[Capacity];

	// ** 초기화
	for (int i = 0; i <= Capacity; i++)
		Temp[1] = NULL;

	// ** 위치 전까지의 값을 복사
	for (int i = 0; i < _where; i++)
		Temp[i] = Vector[i];

	// ** 해당 위치에 값을 삽입
	Temp[_where] = _Value;
	++Size;

	// ** 
	for (int i = _where + 1; i < Size; ++i)
		Temp[i] = Vector[i + (-1)];

	if (Vector)
	{
		delete Vector;
		Vector = nullptr;
	}

	Vector = Temp;
}

// ** 값을 복사하기 때문에 Call by Value
// ** 데이터가 보존되어 있는 형태 (영역이 지워져도 값은 그대로 남는다)
// 
// ** const int& <- 주소(Reference) 연산자
// ** 주소를 복사하기 때문에 Call by Reference
// ** 데이터 자체는 heap 영역에 올라가게 된다.
// ** 주소를 불러오기 때문에 영역이 지워지면 값이 바뀌는 경우가 생긴다.