#include <iostream>
#include <vector>
#define MAX 1000000
#define Moduler 1000000009
using namespace std;

int main(int argc, char** argv) 
{
	vector<int> dp; //dp[n] = dp[n-1]+dp[n-2]+dp[n-3]
	
	dp.push_back(0); //dp[0]
	dp.push_back(1); //dp[1]
	dp.push_back(2); //dp[2]
	dp.push_back(4); //dp[3]

	//dp[4] บฮลอ
	for (int i = 4; i <= MAX; i++) {
		long long num;
		num = (dp[i - 1] + dp[i - 2] + dp[i - 3])% Moduler;
		dp.push_back(num);
	}

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
	

	return 0;
}