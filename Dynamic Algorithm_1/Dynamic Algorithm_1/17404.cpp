#include <iostream>
#define MAX 1000
using namespace std;

int dp[MAX + 1][3];
int arr[MAX + 1][3];
int main(int argc, char** argv) 
{

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]);
		if (i == n) {
			if (dp[i][0] == dp[i - 1][1]) {
				dp[i][0] += arr[i][2];
			}
			else if (dp[i][0] == dp[i - 1][2]) {
				dp[i][0] += arr[i][1];
			}
		}
		else {
			dp[i][0] += arr[i][0];
		}
	
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
		if (i == n) {
			if (dp[i][1] == dp[i - 1][0]) {
				dp[i][1] += arr[i][2];
			}
			else if (dp[i][1] == dp[i - 1][2]) {
				dp[i][1] += arr[i][0];
			}
		}
		else {
			dp[i][1] += arr[i][1];
		}
		

		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
		if (i == n) {
			if (dp[i][2] == dp[i - 1][0]) {
				dp[i][2] += arr[i][1];
			}
			else if (dp[i][2] == dp[i - 1][1]) {
				dp[i][2] += arr[i][0];
			}
		}
		else {
			dp[i][2] += arr[i][2];
		}
		

	}

	int answer = min(dp[n][0], dp[n][1]);
	answer = min(answer, dp[n][2]);

	cout << answer;


	return 0;
}