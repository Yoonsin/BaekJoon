#include <iostream>
#include <cmath>
#define MAX 1000000
using namespace std;

//https://minyeok2ee.gitlab.io/boj/boj-17103/ Âü°í

int arr[MAX + 1]{ 0, };

int main(int argc, char** argv) {
	
	for (int i = 2; i <= MAX; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= sqrt(MAX); i++) {
		if (arr[i] == 0) {
			continue;
		}
		for (int j = i * i; j <= MAX; j += i) {
			arr[j] = 0;
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int cnt = 0;
		for (int i = 2; i < n; i++) {
			if (arr[n - i] + arr[i] == n)
			{
				cnt++;
				if (n - i == i) {
					cnt++;
				}
			}
		}

		cout << cnt / 2 << '\n';
	}
	

	return 0;
}