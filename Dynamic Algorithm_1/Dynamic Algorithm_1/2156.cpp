#include <iostream>
#define MAX 10000
using namespace std;

//dp[n] = 1~n���� �־����� �� �ִ�� ���� �� �ִ� ������ ��
//dp[n][0] = �̹� �� �տ� ������ ������ �� 
//dp[n][1] = �̹� �� �տ� ������ ������ �� 
//dp[n][2] = �� �վտ� ������ ������ �� 
//dp[n][3] = �� �տ� ������ ������ �ʾ��� ��

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