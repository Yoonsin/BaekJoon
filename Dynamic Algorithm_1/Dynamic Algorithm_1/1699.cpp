#include <iostream>
#include <cmath>
#define MAX 100001
using namespace std;

int dp[MAX];
int main(int argc, char** argv) 
{
	int n;
	cin >> n;

	dp[1] = 1; //1^2
	dp[2] = 2; //1^2 + 1^2
	for (int i = 3; i <= MAX ; i++) 
	{
		if (sqrt(i) - (int)sqrt(i) > 0) {
			int a;
			for (int j = i - 1; j > 0; j--) {
				if (sqrt(j) - (int)sqrt(j) == 0) {
					a = j;
					break;
				}
			}

			dp[i] = dp[a] + dp[i - a];
		}
		else {
			//i°¡ Á¦°ö¼ö¸é
			dp[i] = 1;
		}

	}
	
	cout << dp[n];


	return 0;
}