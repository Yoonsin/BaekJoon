#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int main(int argc, char** argv) 
{
	//A���� -> 10���� -> B����

	int a, b, m;
	stack<int> s;

	cin >> a >> b;
	cin >> m;

	while (m--) {
		int a_num;
		cin >> a_num;
		s.push(a_num);
		//m�� 2���� �� �� ���ȿ��� m�� 2 1�� �ƴ϶� 1 0�̱���
	}

	//A���� -> 10����
	int sum=0;

	for (int i = 0; !s.empty(); i++) {
		sum += pow(a, i) * s.top();
		s.pop();
	}

	//10���� -> B����
	do {
		s.push(sum % b);
		sum /= b;

	} while (sum != 0);

	for (int i = 0; !s.empty(); i++) {
		cout << s.top() << ' ';
		s.pop();
	}



	return 0;
}