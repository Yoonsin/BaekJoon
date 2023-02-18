//참고 https://lmcoa15.tistory.com/43
#include <iostream>
#define MAX 100001
using namespace std;

int dp[MAX];
int main(int argc, char** argv) 
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		dp[i] = i; //1^2만 모두 더한 경우
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[n] << '\n';


	return 0;
}