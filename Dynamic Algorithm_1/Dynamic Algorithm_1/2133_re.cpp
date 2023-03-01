#include <iostream>
#define MAX 30
using namespace std;

//���� : https://yabmoons.tistory.com/536 �幮���� ���̴�
//dp[n] = a  3xnũ���� ���� 2x1,1x2 Ÿ�ϵ�θ� ä�� ��, ä�� �� �ִ� ����� ���� �� a���̴�.

int dp[MAX + 1];
int main(int argc, char** argv) {
	int n;
	cin >> n;

	//n�� Ȧ���� ���� �� �ִ� ����� ���� 0.
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