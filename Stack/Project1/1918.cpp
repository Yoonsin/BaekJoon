#include <iostream>
#include <string>
#include <stack>
using namespace std;

int prec(char op) {
	
	if (op == '(' || op == ')') {
		return 0;
	}
	else if (op == '+' || op == '-') {
		return 1;
	}
	else if (op == '*' || op == '/') {
		return 2;
	}

	return -1;
}


int main(int argc, char** argv) {

	//�����ڸ� ���ÿ� �ְ�
	//�ǿ����ڸ� ��� ����ϱ�

	stack<char> s;
	string str;
	char cr;
	
	cin >> str;
	
	for (int i = 0; i < str.size(); i++) {
		cr = str[i];

		if (cr == '(') {
			s.push(cr);
		}
		else if (cr == ')') {
			while (!(s.top() == '(')) {
				cout << s.top();
				s.pop();
			}
			s.pop(); //( ���ֱ�
		}
		else if (cr == '+' || cr == '-' || cr == '*' || cr == '/') {

		    while (!s.empty() && prec(s.top()) >= prec(cr)) //�켱������ ���ų� ������ ��� �̱� (�����͵� �̴� ������ �����Ŷ� ������� ����ϱ� ������)
		    {
					cout << s.top();
					s.pop();
		    }
			
			s.push(cr);
		}
		else {
			cout << cr;
		}
		
	}

	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}

	return 0;
}