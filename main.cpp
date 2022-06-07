// ** Vector v0.8a
#include <iostream>

using namespace std;

// ** ������ ����
int Size = 0;

// ** �ִ� ���� ����
int Capacity = 0;

// ** �����̳�
int* Vector = nullptr;





// ** �����̳��� ������ ��ġ�� ���� �߰�.
void push_back(const int& _Value);

// ** �����̳��� ������ ��ġ�� ���� ����.
void pop_back();

int front();

int back();

void erase(const int _where);


int main(void)
{
	// ** ���� Ƚ����ŭ ��ȿ��
	for (int i = 0; i < 10; ++i)
		push_back(i * 100 + 100);

	pop_back();

	for (int i = 0; i < Size; ++i)
	{
		cout << "Value: " << Vector[i] << endl;
	}

	erase(3);

	for (int i = 0; i < Size; ++i)
	{
		cout << "Value: " << Vector[i] << endl;
	}

	cout << endl << front() << endl;
	cout << back() << endl;

	return 0;
}

void push_back(const int& _Value)
{
	if (Capacity <= Size)
	{
		Capacity += (Capacity <= 3) ? 1 : Capacity >> 1;

		int* Temp = new int[Capacity];

		for (int i = 0; i < Size; ++i)
			Temp[i] = Vector[i];

		if (Vector)
		{
			delete Vector;
			Vector = nullptr;
		}

		Temp[Size] = _Value;
		Vector = Temp;
	}
	else
	{
		Vector[Size] = _Value;
	}

	++Size;

	cout << "Value: " << _Value << endl;
	cout << "Size : " << Size << endl;
	cout << "Capacity : " << Capacity << endl << endl;

}

void pop_back()
{
	--Size;
}

int front()
{
	return Vector[0];
}

int back()
{
	return Vector[Size - 1];
}

void erase(const int _where)
{
	// ** Ư�� ��ġ�� �ִ� ���Ҹ� �����ϰ� ����

	--Size;
	
	for (int i = _where + (-1); i < Size -1; i++)
	{
		Vector[i] = Vector[i + 1];
	}
}

// ** insert �Լ� ���� Ư�� ��ġ�� �����͸� ������ �� �ִ� �Լ��� ���� ��