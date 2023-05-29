#include <iostream>
#include <string>
#include <algorithm>
#define MAX 4
using namespace std;

int arr[MAX][MAX];
int main(int argc, char** argv)
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < m; j++)
		{
			arr[i][j] = str[j] -'0';
		}
	}

	int ans = -1;

	//자릿수 하나씩 판단
	for (int b = 0; b < (1 << n * m); b++)
	{
		//가로 계산
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			int now = 0;
			for (int j = 0; j < m; j++)
			{
				int k = i * m + j;

				//b가 가로이면 == 0
				if ((b & (1 << k)) == 0)
				{
					now = now * 10 + arr[i][j];
				}
				else {
					sum += now;
					now = 0;
				}
			}

			sum += now;
		}

		//세로 계산
		for (int i = 0; i < m; i++)
		{
			int now = 0;
			for (int j = 0; j < n; j++)
			{
				int k = j * m + i;

				//b가 세로이면 ==1
				if ((b & (1 << k)) != 0)
				{
					now = now * 10 + arr[j][i];
				}
				else {
					sum += now;
					now = 0;
				}
			}

			sum += now;
		}

		ans = max(ans, sum);
	}

	cout << ans;



	return 0;
}