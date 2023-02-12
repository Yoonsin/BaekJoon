#include <iostream>
#define MOD 1000000000
using namespace std;

int main(int argc, char** argv) 
{
	int n;
	int dp[101][10];
	
	dp[1][0] = 0;
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= 100; i++) {
		
		for (int j = 0; j < 10; j++) {
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j + 1]%MOD;
			}
			else if (j == 9)
			{
				dp[i][j] = dp[i - 1][j - 1] %MOD;
			}
			else {
				dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1])%MOD;
			}
		}
	}
	
	long long sum = 0;
	cin >> n;

	for (int i = 0; i < 10; i++) {
		sum += dp[n][i];
	}
	
	

	cout << sum % MOD;
	
	

	return 0;
}