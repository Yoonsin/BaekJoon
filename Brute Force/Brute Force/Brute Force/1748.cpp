#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char** argv) 
{
	int n;
	cin >> n;
	
	int i = 1; //�ڸ���
	int answer = 0; //1~n������ ���� �̾ �� ���� �ڸ���
	while (true)
	{
		if (n < (pow(10, i)-1) ) {
			//n�� i�ڸ� ��
			//ex) i:3 n:120 �� �� 120 < 10^3-1 -> 120 < 999
			answer += i * ((n - pow(10, (i - 1)))+1);
			break;
		}
		else {
			answer += i * (pow(10, (i - 1)) * 9);
		}

		i++;
	}

	cout << answer;
	return 0;
}