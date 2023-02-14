#include <iostream>
#include <vector>
using namespace std;

//https://cocoon1787.tistory.com/455 //참고
int main(int argc, char** argv) 
{
	//dp[n] : 수열 A에서 길이 N까지의 가장 긴 증가하는 부분 수열, 수열 길이
	struct DP {
		vector<int> arr; //부분 수열 
		int length;      //부분 수열의 길이
	};

	
	vector<int> a;
	vector<struct DP> dp;
	
	int ans_length, ans_arr_idx;
	ans_length = ans_arr_idx = 0;

	int n;
	cin >> n;

	

	for (int i = 0; i < n; i++) {

		int num;
		cin >> num;
		a.push_back(num);

		struct DP d = { {},0 };
		dp.push_back(d);

		for (int j = 0; j < a.size(); j++) {
			if (a[j] < a[i]) {
				if (dp[i].length < dp[j].length) {
					dp[i].length = dp[j].length;
					
					dp[i].arr.resize((int)dp[j].arr.size());
					copy(dp[j].arr.begin(), dp[j].arr.end(), dp[i].arr.begin());
				}
			}
		}

		dp[i].length += 1;
		dp[i].arr.push_back(num);

		ans_length = max(ans_length, dp[i].length);

		if (dp[ans_arr_idx].arr.size() < dp[i].arr.size()) {
			ans_arr_idx = i;
		}
		
	}


	cout << ans_length << '\n';
	for (int i = 0; i < dp[ans_arr_idx].arr.size(); i++) {
		cout << dp[ans_arr_idx].arr[i] << ' ';
	}

	return 0;
}