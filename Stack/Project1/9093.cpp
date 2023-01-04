#include <iostream>
#include <string>
using namespace std;

int s = 0; //stack의 size
char stack[1001];

void push(char cr)
{
	stack[s] = cr;
	s++;
}
bool empty()
{
	if (s == 0)
	{
		return true;
	}
	else {
		return false;
	}
}
char pop()
{
	if (s == 0) return -1;
	char cr = stack[s - 1];
	s--;
	return cr;
}
int size()
{
	return s;
}

int main(int argc, char* argv[]) {
	int t; //테스트 케이스 
	cin >> t;
	cin.ignore();

	while (t--)
	{
		string str;
		getline(cin, str);

		str += '\n';

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ' ' || str[i] == '\n') { //만약 해당 문자가 공백 또는 \n이라면
				while (!empty()) {
					cout << pop();
				}
				cout << ' ';
			}
			else if(str[i] != ' ') {
				push(str[i]);
			}
		}
		cout << '\n';
	}
	
	return 0;
}