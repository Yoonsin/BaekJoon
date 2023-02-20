#include <iostream>
#define MAX 201
#define Moduler 1000000000
using namespace std;

long long dp[MAX][MAX]; //dp[k][n]
int main(int argc, char** argv) {

	int N, K;
	cin >> N >> K;

	for (int i = 0; i <= N; i++) {
		dp[1][i] = 1;
	}

	for (int k = 2; k <= K; k++) {
		for (int n = 0; n <= N; n++) {
			for (int i = 0; i <= n; i++) {
				dp[k][n] = dp[k][n] + dp[k - 1][i];
			}
			dp[k][n] = dp[k][n] % Moduler;
		}
	}
	
	cout << dp[K][N] << '\n';

	return 0;
}