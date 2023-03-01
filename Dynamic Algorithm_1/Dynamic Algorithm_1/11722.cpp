#include <iostream>
#define MAX 1000
using namespace std;

int arr[MAX + 1];
int dp[MAX+1];

int main(int argc, char** argv) {

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int max_num = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (arr[i] < arr[j]) {
				if (dp[i] < dp[j]) {
					dp[i] = dp[j];
				}
			}
		}

		dp[i] += 1;

		max_num = max(max_num, dp[i]);
	}

	cout << max_num;

	return 0;
}