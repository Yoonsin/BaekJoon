#include <iostream>
#define MAX 90
using namespace std;

int main(int argc, char** argv) {
	
	long long dp[MAX + 1][2]; //ex) dp[n][0] -> n의 길이를 가지고, 0으로 끝나는 이친수
	dp[1][0] = dp[2][1] = 0;
	dp[1][1] = dp[2][0] = 1;

	int n;
	cin >> n;

	for (int i = 3; i <= MAX; i++) 
	{
		dp[i][0] = dp[i - 1][1] + dp[i - 1][0];
		dp[i][1] = dp[i - 1][0];
	}

	cout << dp[n][0] + dp[n][1];




	return 0;
}