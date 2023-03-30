#include <iostream>
#include <algorithm>
#define MAX 15
using namespace std;

int dp[MAX];
int T[MAX];
int P[MAX];

//참고 : https://songsunbi.tistory.com/80
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
		//j : 간격  k : 해당하는 날
		for (int j = 1, k = i; k >= 0; j++, k--) {
			if (T[k] == j) {
				if (i - j < 0) { //dp[i-j]가 dp[-1]일 수도 있을 때. 이때는 dp[i-j]를 0으로 가정한다.
					dp[i] = max(dp[i], P[k]);
				}
				else {
					for (int x = i - j; x >= 0; x--) { //오늘 이전 날들 ( 0~i-1 )까지의 dp값을 다 고려해봐야 한다.
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