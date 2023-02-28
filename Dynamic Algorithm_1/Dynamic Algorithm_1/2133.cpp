#include <iostream>
#define MAX 30
using namespace std;

int dp[MAX + 1][6];
int main(int argc, char** argv) {
	int n;
	cin >> n;

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			switch (i)
			{
			case 1:
				dp[i][j] = 1;
				break;
			case 2:
				dp[i][j] = 0;
				break;
			case 3:
				dp[i][j] = 3;
				break;
			default:
				break;
			}
		}
	}

	for (int i = 4; i <= n; i++) {
		for (int j = 1; j <= 5; j++) {
			dp[i][j] = dp[i - 2][1] + dp[i - 2][2] + dp[i - 2][3] + dp[i - 4][4] + dp[i - 4][5];
		}
	}

	int sum = 0;
	for (int i = 1; i <= 5; i++) {
		sum += dp[n][i];
	}

	cout << sum;

	return 0;
}