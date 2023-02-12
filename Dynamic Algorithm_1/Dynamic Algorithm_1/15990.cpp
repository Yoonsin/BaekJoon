#include <iostream>
#define MAX 100000
#define MOD 1000000009
using namespace std;


int dp[MAX + 1][4];
int main(int argc, char** argv) 
{
	int t;
	cin >> t;

	

	dp[1][1] = 1;
	dp[1][2] = dp[1][3] = 0;

	dp[2][2] = 1;
	dp[2][1] = dp[2][3] = 0;

	dp[3][1] = dp[3][2] = dp[3][3] = 1;

	for (int i = 4; i <= MAX; i++)
	{
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;

	}

	while (t--)
	{
		int n;
		cin >> n;

	
		cout << ((long long)dp[n][1] + dp[n][2] + dp[n][3]) % MOD << '\n';

	}

	return 0;
}