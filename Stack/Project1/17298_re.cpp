#include <iostream>
#include <stack>
using namespace std;

//https://cocoon1787.tistory.com/347 Âü°í
int main(int argc, char** argv)
{
	int t;
	stack<int> s;
	int ans[1000001];
	int num[1000001];

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> num[i];
	}

	for (int i = t - 1; i >= 0; i--) {
		while (!s.empty() && s.top() <= num[i])
			s.pop();

		if (s.empty()) ans[i] = -1;
		else ans[i] = s.top();

		s.push(num[i]);
	}

	for (int i = 0; i < t; i++)
		cout << ans[i] << " ";

	return 0;
}