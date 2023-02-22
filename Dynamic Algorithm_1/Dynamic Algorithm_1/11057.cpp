#include <iostream>
#define MAX 1000
#define Moduler 10007
using namespace std;

int dp[MAX+1][10]; //dp[n][0] : n번째 자리가 0인 오르막수 dp[n][1] : n번째 자리가 1인 오르막수 ... dp[n][9] : n번째 자리가 9인 오르막수
int main(int argc, char** argv) 
{
	int n;
	cin >> n;

	//dp[1][0]~dp[1][9]는 전부다 1로 초기화
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k >= 0; k--) {
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % Moduler;
			}
			
		}
	}
	
	int sum = 0;

	for (int i = 0; i < 10; i++) {
		sum = (sum + dp[n][i]) % Moduler;
	}

	cout << sum;

	return 0;
}