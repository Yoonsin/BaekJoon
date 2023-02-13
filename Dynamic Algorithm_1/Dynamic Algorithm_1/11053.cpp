#include <iostream>
#include <vector>
#define MAX 1000
using namespace std;

// https://hwan-shell.tistory.com/299 참고
int main(int argc, char** argv) 
{
	int n;
	vector<int> v;
	int dp[MAX+1]; //dp[n] : n의 길이에서 가장 긴 증가하는 부분 수열의 길이
	dp[0] = 0;
	int ans = 0; 

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
		
		dp[i] = 0;
		int max_dp = 0;

		for (int j = 0 ; j < v.size(); j++) 
		{
			if (v[j] < v[i]) 
			{
				if (max_dp < dp[j]) {
					dp[i] = dp[j];
					max_dp = dp[j];
				}
			}
		}

		dp[i] += 1;
		ans = max(dp[i], ans);
	}

	cout << ans;


	return 0;
}