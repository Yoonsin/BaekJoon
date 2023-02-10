#include <iostream>
#define MAX 10001
using namespace std;

int main(int argc, char** argv) 
{
	int n;
	cin >> n;

	int* card = new int[n + 1];
	int* dp = new int[n + 1];

	for (int i = 1; i <= n; i++) {
		cin >> card[i];
		dp[i] = MAX; //최대값+1 로 초기화 안하면 결과로 쓰레기 값이 출력됨
	}


	card[0] = dp[0] = 0;
   

	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= i; j++) 
		{
			dp[i] = min(dp[i], card[j] + dp[i - j]);
		}
	}

	cout << dp[n];

	delete[] card, dp;

	return 0;
}