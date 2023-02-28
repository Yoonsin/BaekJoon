#include <iostream>
#define MAX 30
using namespace std;

//참고 : https://yabmoons.tistory.com/536 얍문님은 신이다
//dp[n] = a  3xn크기의 벽을 2x1,1x2 타일들로만 채울 때, 채울 수 있는 경우의 수는 총 a개이다.

int dp[MAX + 1];
int main(int argc, char** argv) {
	int n;
	cin >> n;

	//n이 홀수면 만들 수 있는 경우의 수는 0.
	if (n % 2 == 1) {
		cout << 0 << '\n';
		return 0;
	}

	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;

	for (int i = 4; i <= n; i += 2) {
		dp[i] = dp[i - 2] * dp[2];
		for (int j = i - 4; j >= 0; j -= 2) {
			dp[i] = dp[i] + (dp[j] * 2);
		}
	}

	cout << dp[n] << '\n';

	return 0;
}