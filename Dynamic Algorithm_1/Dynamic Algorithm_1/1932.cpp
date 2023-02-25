#include <iostream>
#define MAX 500
using namespace std;

int arr[MAX + 1][MAX + 1];
int dp[MAX + 1][MAX + 1];
int main(int argc, char** argv) 
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
			if (j == 1) {
				dp[i][j] = dp[i - 1][1] + arr[i][j];
			}
			else if (j == i) {
				dp[i][j] = dp[i - 1][j-1] + arr[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
			}
		}
	}

	int max_sum = -1;
	for (int i = 1; i <= n; i++) {
		max_sum = max(max_sum, dp[n][i]);
	}

	cout << max_sum << '\n';


	return 0;
}