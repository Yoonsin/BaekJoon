//Âü°í https://yabmoons.tistory.com/128
#include <iostream>
#define MAX 200
using namespace std;

long long dp[MAX + 1][MAX + 1];
int main(int argc, char** argv) 
{
	int n, k;
	cin >> n >> k;

	for (int i = 0; i <= k; i++) {
		dp[1][i] = i;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000000;
		}
	}


	cout << dp[n][k];

	return 0;
}