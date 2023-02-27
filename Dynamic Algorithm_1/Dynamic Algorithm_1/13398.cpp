#include <iostream>
#define MAX 100000
#define MIN -100000000
using namespace std;

int arr[MAX + 1];
int dp[MAX + 1]; //수를 하나 제거하지 않았을 때의 최대 연속합
int dp_2[MAX + 1]; //수를 하나 제거했을 때의 최대 연속합
int main(int argc, char** argv) 
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp_2[i] = MIN - 1;
	}

	int answer = MIN - 1;

	for (int i = 1; i <= n; i++) {
		if (dp[i - 1] < 0) {
			dp[i] = arr[i]; //이전까지의 연속합이 음수면 끊고 현재 라운드 원소부터 다시 시작
		}
		else {
			dp[i] = dp[i - 1];
			dp[i] += arr[i];
		}

		int num = MIN - 1;
		for (int j = 1; j <= i-1; j++) {
			if (arr[j] < 0) {
				if (arr[j + 1] > 0) {
					//cout << "dp " << j - 1 << " : " << dp[j - 1] << '\n';
					num = dp[j - 1];
					for (int k = j+1; k <= i; k++) {
						num += arr[k];
					}
					
				}
			}
			



			dp_2[i] = max(num, dp_2[i]);
		}

		

		answer = max(answer, dp[i]);
		answer = max(answer, dp_2[i]);

	}

	cout << answer;

	return 0;
}