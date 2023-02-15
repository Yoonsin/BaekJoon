#include <iostream>
#include <vector>
#define MAX 1000000
using namespace std;

int arr[MAX];
int main(int argc, char** argv) 
{
	int n;
	cin >> n;

	vector<int> dp; //길이 N에서의 연속 합중 가장 큰 합

	cin >> arr[0];
	dp.push_back(arr[0]);
	int ans_dp = arr[0];

	for (int i = 1; i < n; i++) {
		cin >> arr[i];
		dp.push_back(arr[i]);

		
		if (dp[i] < dp[i - 1]+dp[i]) {
				dp[i] = dp[i - 1]+dp[i]; 
		}

		

	
		ans_dp = max(ans_dp, dp[i]);
	}

	cout << ans_dp;

	return 0;
}