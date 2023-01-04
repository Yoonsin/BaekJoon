#include <iostream>
#include <string>
using namespace std;

int s=0; //stackÀÇ size
int stack[10001];

void push(int n)
{
	stack[s] = n;
	s++;
}
int pop()
{
	if (s == 0) return -1;
	int t = stack[s - 1];
	s--;
	return t;
}
int top()
{
	if (s == 0) return -1;
	else return stack[s - 1];
}
int size()
{
	return s;
}
int empty()
{
	if (s == 0) return 1;
	else return 0;
}


int main(int argc, char* argv[]) {
	
	int cnt;
	cin >> cnt;
	
	while (cnt--)
	{
		string str;
		cin >> str;
		
		if (str == "push") {
			int n;
			cin >> n;
			push(n);
		}
		if (str == "pop") {
			cout << pop() << endl;
		}
		if (str == "top") {
			cout << top() << endl;
		}
		if (str == "size") {
			cout << size() << endl;
		}
		if (str == "empty") {
			cout << empty() << endl;
		}
	}

	
	return 0;
}