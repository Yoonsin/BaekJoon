#include <iostream>
#include <vector>
#include <string.h>
#define MAX 100000
using namespace std;

int sticker[2][MAX + 1];
int dp[2][MAX + 1];

int main(int argc, char** argv) 
{
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		
		for (int i = 0; i < 2; i++) {
			memset(sticker[i], 0, sizeof(int) * (MAX + 1));
			memset(dp[i], 0, sizeof(int) * (MAX + 1));
		}


		for (int i = 0; i <= 1; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> sticker[i][j];
			}
		}
		
		dp[0][1] = sticker[0][1];
		dp[1][1] = sticker[1][1];

	     
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j <= 1; j++) {
				if (j == 0) {
					dp[j][i] = max(dp[j + 1][i - 1], dp[j][i - 2]);
					dp[j][i] = max(dp[j][i], dp[j + 1][i - 2]);
					dp[j][i] += sticker[j][i];
				}
				else if (j == 1) {
					dp[j][i] = max(dp[j-1][i - 1], dp[j][i - 2]);
					dp[j][i] = max(dp[j][i], dp[j - 1][i - 2]);
					dp[j][i] += sticker[j][i];
				}
			}
		}
		
		cout << max(dp[0][n], dp[1][n]) << '\n';
	
	}



	return 0;
}