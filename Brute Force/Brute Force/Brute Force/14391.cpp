#include <iostream>
#include <string>
using namespace std;

//https://regularmember.tistory.com/90 참고
int n, m;
int paper[4][4];

int main(int argc, char** argv)
{
	cin >> n >> m;
	string s;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			paper[i][j] = s[j] - '0';
		}
	}

	int ans = 0;

	for (int b = 0; b < (1 << (n * m)); b++) {
		int sum = 0;

		for (int i = 0; i < n; i++) {
			int now = 0;
			for (int j = 0; j < m; j++) {
				int k = i * m+j;

				if ((b & (1 << k)) == 0) {
					now = now * 10 + paper[i][j];
				}
				else {
					sum += now;
					now = 0;
				}
			}

			sum += now;
		}

		for (int j = 0; j < m; j++) {
			int now = 0;
			for (int i = 0; i < n; i++) {
				int k = i * m + j;

				if ((b & (1 << k)) != 0) { //여기가 핵심
					now = now * 10 + paper[i][j];
				}
				else {
					sum += now;
					now = 0;
				}
			}
		 
			sum += now;
 		
		}
	
		if (ans < sum)ans = sum;
	
	}

	cout << ans << '\n';
	return 0;

	

}