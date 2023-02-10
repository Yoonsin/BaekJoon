#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
	int n;
	cin >> n;

	//card[n] = ī�� n���� ��µ� ��� ���
	//dp[n] = ī�� n���� ��µ� ��� �ִ� ���
	int* card = new int[n+1];
	int* dp = new int[n+1];

	for (int i = 1; i <= n; i++) 
	{
		cin >> card[i];
	}
	
	card[0] = dp[0] = 0;
	dp[1] = 0;
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + card[j]);
		}
	}

	cout << dp[n] << '\n';
	
	delete[] card, dp;



	return 0;
}