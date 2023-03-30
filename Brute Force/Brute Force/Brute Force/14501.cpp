#include <iostream>
#include <algorithm>
#define MAX 15
using namespace std;

int dp[MAX];
int T[MAX];
int P[MAX];

//���� : https://songsunbi.tistory.com/80
int main(int argc, char** argv)
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int t, p;
		cin >> t >> p;

		T[i] = t;
		P[i] = p;
	}

	int answer = 0;

	for (int i = 0; i < N; i++)
	{
		//j : ����  k : �ش��ϴ� ��
		for (int j = 1, k = i; k >= 0; j++, k--) {
			if (T[k] == j) {
				if (i - j < 0) { //dp[i-j]�� dp[-1]�� ���� ���� ��. �̶��� dp[i-j]�� 0���� �����Ѵ�.
					dp[i] = max(dp[i], P[k]);
				}
				else {
					for (int x = i - j; x >= 0; x--) { //���� ���� ���� ( 0~i-1 )������ dp���� �� ����غ��� �Ѵ�.
						dp[i] = max(dp[i], dp[x] + P[k]);
					}
					
				}
			}
		}
		answer = max(answer, dp[i]);
	}

	cout << answer;
	

	return 0;
}