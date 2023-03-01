#include <iostream>
#define MAX 1000
using namespace std;

int arr[MAX + 1];
int dp[MAX + 1]; //dp[n] :  n번째 원소까지 왔을 떄 합이 가장 큰 증가 부분 수열의 합
int main(int argc, char** argv) {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1] = arr[1];
	int max_sum = dp[1];

	for (int i = 2; i <= n; i++) {
		for (int j = i - 1; j >= 1; j--) {
			if (arr[j] < arr[i]) {
				if (dp[j] > dp[i]) {
					dp[i] = dp[j];
				}
			}
		}

		dp[i] += arr[i];
		max_sum = max(max_sum, dp[i]);
	}

	

	cout << max_sum;



	return 0;
}