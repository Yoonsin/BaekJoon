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

	//연산자만 스택에 넣고
	//피연산자만 계속 출력하기

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
			s.pop(); //( 빼주기
		}
		else if (cr == '+' || cr == '-' || cr == '*' || cr == '/') {

		    while (!s.empty() && prec(s.top()) >= prec(cr)) //우선순위가 같거나 높으면 계속 뽑기 (같은것도 뽑는 이유는 같은거라도 순서대로 계산하기 때문에)
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