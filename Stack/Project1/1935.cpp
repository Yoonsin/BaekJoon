#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(int argc, char** argv)
{
	stack<double> s; //�ǿ����� �ִ� ����
	double op[26]; //0~25 ���� �� 26���� �ǿ�����

	double n;
	string exp;


	cin >> n;
	cin >> exp;

	for (int i = 0; i < n; i++) {
		double op_num;
		cin >> op_num;
		op[i] = op_num;
	}


	for (int i = 0; i < exp.size(); i++) {
		if (exp[i] == '+') {
			double second = s.top(); s.pop();
			double first = s.top(); s.pop();
			s.push(first + second);
		}
		else if (exp[i] == '-') {
			double second = s.top(); s.pop();
			double first = s.top(); s.pop();
			s.push(first - second);
		}
		else if (exp[i] == '/') {
			double second = s.top(); s.pop();
			double first = s.top(); s.pop();
			s.push(first / second);
		}
		else if (exp[i] == '*') {
			double second = s.top(); s.pop();
			double first = s.top(); s.pop();
			s.push(first * second);
		}
		else {
			s.push(op[exp[i]-65]); //65
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << s.top(); 
	s.pop();



	return 0;
}