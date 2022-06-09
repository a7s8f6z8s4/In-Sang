// ** Vector v0.9
#include <iostream>

using namespace std;

// ** ���� ������ ����
int Size = 0;

// ** �ִ� ���� ����
int Capacity = 0;

// ** �����̳�
int* Vector = nullptr;

// ** �����̳��� ������ ��ġ�� ���� �߰�.
void push_back(const int& _Value);

// ** �����̳��� ������ ��ġ�� ���� ����.
void pop_back();

// ** ���� �� �ʿ� �ִ� ����
int front();

// ** ���� �� �ʿ� �ִ� ����
int back();

// ** Ư�� ��ġ�� Value ����
void erase(const int _where);

// ** Ư�� ��ġ�� Value �߰�
void Insert(const int& _where, const int& _Value);

int main(void)
{
	// ** �� �߰�
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
	// ** ���� �� �̻� ������ �� �ִ� ������ ���ٸ�
	if (Capacity <= Size)
	{
		// ** ���� ���뷮�� 4���� �۴ٸ� 1�� �����ϰ�
		// ** ���� ���뷮�� 4���� ũ�ų� ���ٸ� 1/2 ��ŭ �߰���
		Capacity += (Capacity <= 3) ? 1 : Capacity >> 1;

		// ** �ӽ� ����� Temp ����
		int* Temp = new int[Capacity];

		// ** ������ ������ �ʱ�ȭ
		for (int i = 0; i <= Capacity; i++)
			Temp[1] = NULL;

		// ** ������ �ִ� ���� ����
		for (int i = 0; i < Size; ++i)
			Temp[i] = Vector[i];

		// ** ������ ���� ����
		if (Vector)
		{
			delete Vector;
			Vector = nullptr;
		}

		// ** ���� �Ҵ� �� �ӽ��� ��(�ش� �ּ�)�� ����
		Temp[Size] = _Value;

		// ** �ӽ��� �ּҰ��� ���� �ص� ���� �߰��� ���ο� ���� �ٽ� ���������� ����Ǿ� �ִ� Vector�� ������.
		Vector = Temp;
	}
	else
	{
		// ** ������ ��ġ�� �� �߰�
		Vector[Size] = _Value;
	}

	// ** ���� ������ �ִ밪 ����
	++Size;

}

void pop_back()
{
	--Size;
}

int front()
{
	// ** 0��° ���� ��ȯ
	return Vector[0];
}

int back()
{
	// ** ������ ���� ��ȯ
	return Vector[Size - 1];
}

void erase(const int _where)
{
	// ** ���� ������ �ִ밪 ����
	--Size;
	
	// ** ������
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

	// ** �ӽ� ����� Temp
	int* Temp = new int[Capacity];

	// ** �ʱ�ȭ
	for (int i = 0; i <= Capacity; i++)
		Temp[1] = NULL;

	// ** ��ġ �������� ���� ����
	for (int i = 0; i < _where; i++)
		Temp[i] = Vector[i];

	// ** �ش� ��ġ�� ���� ����
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

// ** ���� �����ϱ� ������ Call by Value
// ** �����Ͱ� �����Ǿ� �ִ� ���� (������ �������� ���� �״�� ���´�)
// 
// ** const int& <- �ּ�(Reference) ������
// ** �ּҸ� �����ϱ� ������ Call by Reference
// ** ������ ��ü�� heap ������ �ö󰡰� �ȴ�.
// ** �ּҸ� �ҷ����� ������ ������ �������� ���� �ٲ�� ��찡 �����.