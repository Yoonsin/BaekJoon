#include <iostream>
#define MAX 10000
using namespace std;

//dp[n] = 1~n잔이 주어졌을 떄 최대로 마실 수 있는 포도주 양
//dp[n][0] = 이미 내 앞에 두잔을 마셨을 때 
//dp[n][1] = 이미 내 앞에 한잔을 마셨을 때 
//dp[n][2] = 내 앞앞에 한잔을 마셨을 떄 
//dp[n][3] = 내 앞에 두잔을 마시지 않았을 떄

int dp[MAX + 1];
int wine[MAX + 1];
int main(int argc, char** argv) 
{
	int n;
	cin >> n;

	for(int i=1;i<=n;i++)
	{
		cin >> wine[i];

	}

	dp[1] = wine[1];
	dp[2] = dp[1] + wine[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i]);
		dp[i] = max(dp[i], dp[i - 1]);
	}

	

	cout << dp[n];


	return 0;
}