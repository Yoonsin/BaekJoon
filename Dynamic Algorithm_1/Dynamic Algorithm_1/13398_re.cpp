#include <iostream>
#define MAX 100000
#define MIN -100000000
using namespace std;

int arr[MAX + 1];
int dp[MAX + 1][2]; //[0]:삭제 해줬을 떄 [1]: 삭제 하지않았을 때
//https://seol-limit.tistory.com/46 참고

int main(int argc, char** argv)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int ans = MIN - 1;
	dp[0][0] = dp[0][1] = MIN - 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][1],dp[i-1][0]+arr[i]);
		dp[i][1] = max(dp[i - 1][1]+arr[i], arr[i]);
		ans = max(ans, dp[i][0]);
		ans = max(ans, dp[i][1]);
	}

	cout << ans;

	return 0;
}