#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

//큐랑 스택 이용해서 씀
//근데 bool 이용해서 태그인지 아닌지 판별 가능하게 하고 스택만 쓰는게 더 직관적인듯
int main(int argc, char** argv) {
	string str;
	char cr;
	queue<char> q;
	stack<char> s;
	getline(cin, str, '\n');//공백 문자도 받아야 해서 >>연산자 말고 getline로 문자열 입력 받아야함
	for (int i = 0; i < str.size(); i++) {
		q.push(str[i]);
	}

	while (!q.empty())
	{
		cr = q.front(); 
		if (cr == '<') {
			while (!s.empty())
			{
				cout << s.top();
				s.pop();
			}
			while (cr != '>')
			{
				cr = q.front();
				cout << cr;
				q.pop();
			}
		}
		else if (cr == ' ') {
			q.pop();
			while (!s.empty())
			{
				cout << s.top();
				s.pop();
			}
			cout << ' ';
		}
		else {
			
			s.push(cr);
			q.pop();
			
		}
		
	}

	while (!s.empty()) //만약 태그 없이 문자열만 나왔을 경우..
	{
		cout << s.top();
		s.pop();
	}
	
	
	return 0;
}