#include <iostream>
#include <stack>
using namespace std;

int arr[1000001] = { 0 };
int ans[1000001] = { 0 };
int f[1000001] = { 0 }; //1~1000000 사용해야함

int main(int argc, char** argv) {
	
	int t; 
	int n;
	
	

	stack<int> s;

	cin >> t;


	for (int i = 0; i < t; i++) {
		cin >> n;
		arr[i] = n;
		f[arr[i]] += 1;
	}

	for (int i = t - 1; i >= 0; i--) {
		while (!s.empty() && f[s.top()] <= f[arr[i]]) {
			s.pop();
		}

		if (s.empty()) {
			ans[i] = -1;
		}
		else
		{
			ans[i] = s.top();
			
		}

		s.push(arr[i]);
	}

	for (int i = 0; i < t; i++ ) {
		cout << ans[i] << ' ';
	}


	
	return 0;
}