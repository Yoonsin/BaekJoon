#include <iostream>
#define MAX 1000
#define MAX_NUM 1000001
using namespace std;

int arr[MAX + 1][3];
int dp[MAX + 1][3];
int main(int argc, char** argv)
{
	int n;
	cin >> n;

	int answer = MAX_NUM;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) dp[1][j] = arr[1][j];
			else dp[1][j] = MAX + 1;
		}

		for (int j = 2; j <= n; j++) {
			dp[j][0] = arr[j][0] + min(dp[j - 1][1], dp[j - 1][2]);
			dp[j][1] = arr[j][1] + min(dp[j - 1][0], dp[j - 1][2]);
			dp[j][2] = arr[j][2] + min(dp[j - 1][0], dp[j - 1][1]);
		}

		for (int j = 0; j < 3; j++) {
			if (i == j)continue;
			else {
				answer = min(answer, dp[n][j]);
				
			}
			
		}
	}

	cout << answer;


	return 0;
}
