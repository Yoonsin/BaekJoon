#include <iostream>
#define MAX 1000
using namespace std;

int dp[MAX + 1][4]; //dp[n][1] : N��° ���� ���������� ĥ���� ��, 1~N��° ���� ĥ�ϴ� ����� �ּڰ� ([2]: �ʷ�, [3]: �Ķ�)
int color[MAX + 1][4];
int main(int argc, char** argv) 
{
	int t;
	cin >> t;
	
	for (int i = 1; i <= t; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> color[i][j];
		}
	}

	for (int i = 1; i <= t; i++) {
		for (int j = 1; j <= 3; j++) {
			switch (j)
			{
			case 1:
				dp[i][j] = min(dp[i - 1][j + 1], dp[i - 1][j + 2]) + color[i][j];
				break;
			case 2:
				dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j + 1]) + color[i][j];
				break;
			case 3:
				dp[i][j] = min(dp[i - 1][j - 2], dp[i - 1][j - 1]) + color[i][j];
				break;
			default:
				break;
			}
			
		}
	}

	int sum = min(dp[t][1], dp[t][2]);
	sum = min(sum, dp[t][3]);

	cout << sum << '\n';

	return 0;
}