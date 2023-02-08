#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int main(int argc, char** argv) 
{
	//A진법 -> 10진법 -> B진법

	int a, b, m;
	stack<int> s;

	cin >> a >> b;
	cin >> m;

	while (m--) {
		int a_num;
		cin >> a_num;
		s.push(a_num);
		//m이 2였을 때 이 블럭안에서 m은 2 1가 아니라 1 0이구나
	}

	//A진법 -> 10진법
	int sum=0;

	for (int i = 0; !s.empty(); i++) {
		sum += pow(a, i) * s.top();
		s.pop();
	}

	//10진법 -> B진법
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