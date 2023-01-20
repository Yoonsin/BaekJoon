#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

//ť�� ���� �̿��ؼ� ��
//�ٵ� bool �̿��ؼ� �±����� �ƴ��� �Ǻ� �����ϰ� �ϰ� ���ø� ���°� �� �������ε�
int main(int argc, char** argv) {
	string str;
	char cr;
	queue<char> q;
	stack<char> s;
	getline(cin, str, '\n');//���� ���ڵ� �޾ƾ� �ؼ� >>������ ���� getline�� ���ڿ� �Է� �޾ƾ���
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

	while (!s.empty()) //���� �±� ���� ���ڿ��� ������ ���..
	{
		cout << s.top();
		s.pop();
	}
	
	
	return 0;
}