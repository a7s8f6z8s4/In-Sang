#include <iostream>
#include <vector>

using namespace std;



int main(void)
{
	int MAX = 50;

	vector<int> vecNumbers;
//	������ Ÿ��	������ �̸�	(��������)

	// ** ���� �տ� �ִ� (���Ҹ� ��ȯ)
	vecNumbers.front();

	// ** ���� �ڿ� �ִ� (���Ҹ� ��ȯ)
	vecNumbers.back();

	// ** ������ (�ݺ���)
	vecNumbers.begin();

	// ** ���� (�ݺ���)
	vecNumbers.end();

	// ** �Է�
	for (int i = 0; i < 10; i++)
		vecNumbers.push_back(10 * i);
	
	for (int i = 0; i < 10; ++i)
	{
		vecNumbers.push_back(10);
	}

	/*
	for (int i = 0; i < vecNumbers.size(); ++i)
		cout << vecNumbers[i] << endl;

	for (vector<int>::iterator iter = vecNumbers.begin(); iter != vecNumbers.end(); ++iter)
		cout << (*iter) << endl;
	*/

	/*
	for (auto iter = vecNumbers.begin(); iter != vecNumbers.end();)
	{
		if ((*iter) > MAX)
		{
			iter = vecNumbers.erase(iter);
		}
		else
			++iter;
	}

	for (auto iter = vecNumbers.begin(); iter != vecNumbers.end(); ++iter)
		cout << (*iter) << endl;
	*/

	// ��ȯ�Ϸ��� �ϴ� ������ Ÿ�԰� ���� ����Ϸ��� ������ Ÿ���� ���ƾ� ����� �����ϴ�.
	// �������� ������ ���� �� �ִ�.
	/*
	int Array[16];

	for (int i = 1; i < 17; i++)
		Array[i + (-1)] = i;

	int* iterator = Array;

	for (int i = 0; i < 16; i++)
		cout << Array[i] << endl;		<- ��������

	for (int i = 0; i < 16; i++)
		cout << *(iterator + i) << endl;	<- ��������
		cout << *(iterator++) << endl;
	*/

	return 0;
}


// ** char�� 1byte�� �� ����: ������ ��ǻ�� ENIAC�� ���ڸ� ��Ÿ���� ���� ������� ��ǻ��
// ** char �� ǥ������: -128 ~ 127 ���� [ǥ������: 256��]
// ** short �� ǥ������: -32,768 ~ 32,767 ���� [ǥ������: 65,536��] 4byte
// ** int �� ǥ������: -32,768 ~ 32,767 ���� [ǥ������: 65,536��] 4byte
// ** int�� 16bit ��ǻ�Ϳ����� 16bit��, 32bit ��ǻ�Ϳ����� 32bit�� ������ش�. �Ƹ� �� �� ��ÿ� �߰� ������ �ʿ��� �� ����.
// ** long �� ǥ������: -2,147,483,648 ~ 2,147,483,647 ���� [ǥ������: 4,294,967,296��] 8byte

// ** stack ������ ���������� �Լ��� �����Ѵ�

// ** ���� �ݵ�� ���� �������� ���� �����;� �ȴ� -> Call by Reference
// ** ���� �׳� ������ ���� �޾ƿͼ� ó���ҰŴ� -> Call by Value

/*
	{
		int* Pointer = new int;
		// ** �� �Լ��� stack�̴�
	}

	// Pointer �� ģ���� ��� �Ұ���
*/

// ��������
// ** �迭 ����� ���������� �� �ִ� �༮�� �Ұ����ϱ� ������ ����Ѵ�
// ** ������ ����, ������ (�迭�� �ᱹ�� ������)
