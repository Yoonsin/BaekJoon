#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main (int argc, char** argv) {

	string str;
	int b;
	int sum = 0;

	cin >> str >> b;
	
	//�ε����� ������ ���ڸ� ���� ������ �� �ֵ��� �ٲ��ֱ� 
	reverse(str.begin(), str.end()); 
	
	for (int i = 0; i< str.size(); i++) 
	{
		char cr = str[i];
		if (cr >= 'A') {
			//���ĺ�
			sum += pow(b, i) * (cr - 'A' + 10);
			//(����^�ڸ�) * (���� �ڸ���)  
			
		}
		else {
			//0~9���� ����
			sum += pow(b, i) * (cr - '0');
		}

	}

	cout << sum;

	
	return 0;
}