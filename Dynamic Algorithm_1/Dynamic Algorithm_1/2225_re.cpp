#include <iostream>
#define MAX 200
#define Moduler 1000000000
using namespace std;

int dp[MAX + 1][MAX + 1]; //dp[n][k]  0~n까지 k개를 더해서 합이 n이 되는 경우
int main(int argc, char** argv)
{
	int n, k;
	cin >> n >> k;

	//초기화
	for (int i = 0; i <= n; i++) {
		dp[i][1] = 1;
	}

	for (int i = 0; i <= k; i++) {
		dp[0][i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			for (int x = 0; x <= i; x++) {
				dp[i][j] = (dp[i][j] +dp[x][j - 1])%Moduler;
			}
		}
	}

	cout << dp[n][k] << '\n';

	return 0;
}