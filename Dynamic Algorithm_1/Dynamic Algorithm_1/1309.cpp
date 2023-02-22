#include <iostream>
#define MAX 100000
#define Moduler 9901
using namespace std;

//dp[n][0] : N번째 블럭에는 왼쪽 칸만 사자가 살고있음 dp[n][1] : 양쪽 칸에다 사자 안살고 있음  dp[n][2] : 오른쪽 칸만 사자가 살고있음
int dp[MAX + 1][3]; 
int main(int argc, char** argv) 
{

	dp[1][1] = dp[1][2] = dp[1][3] = 1;

	for (int i = 2; i <= MAX; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % Moduler;
		dp[i][2] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % Moduler;
		dp[i][3] = (dp[i - 1][1] + dp[i - 1][2]) % Moduler;
	}

	int n;
	cin >> n;

	cout << (dp[n][1] + dp[n][2] + dp[n][3]) % Moduler;
	return 0;
}