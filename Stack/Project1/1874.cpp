#include <iostream>
#include <stack>
#include <string>
using namespace std;

//https://www.acmicpc.net/problem/1874
//https://guiyum.tistory.com/3 Âü°í

int main() {
	stack<int> s;
	int n;
	string ans;

	cin >> n;
	int m = 0;
	while (n--)
	{
		int x;
		cin >> x;

		if (x > m) {
			while (x>m)
			{
				s.push(++m);
				ans += '+';
			}
			s.pop();
			ans += '-';
		}
		else {
			bool found = false;
			if (!s.empty()) {
				if (x == s.top()) {
					found = true;
				}
				s.pop();
				ans += '-';
			}
			if (!found) {
				cout << "NO" << '\n';
				return 0;
			}
		}
	}

	for (auto x : ans) {
		cout << x << '\n';
	}

	return 0;
}