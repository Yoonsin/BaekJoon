#include <iostream>
using namespace std;


int w(int* arr_a, int* arr_b, int* arr_c)
{
	int a = sizeof(arr_a) / sizeof(*arr_a);
	int b = sizeof(arr_b) / sizeof(*arr_b);
	int c = sizeof(arr_c) / sizeof(*arr_c);

	int ans = 1; //라운드 마다 더하는 값

	//a,b,c에 대한 라운드 각각의 값
	//라운드 0은 1
	arr_a[0] = 1;
	arr_b[0] = 1;
	arr_c[0] = 1;


	int i = 1;
	int j = 1;
	int k = 1;

	//i,j,k가 목표 라운드에 달성할 때 까지 반복
	while (i >= a && j >= b && k >= c)
	{
		if (a <= 0 || b <= 0 || c <= 0)
		{
			return 1;
		}

		if (a > 20 || b > 20 || c > 20)
		{
			a = 20, b = 20, c = 20;
			continue;
		}

		if (a < b && b < c)
		{
			ans += arr_a[i] + arr_b[j] + arr_c[k-1];
			ans += arr_a[i] + arr_b[j - 1] + arr_c[k - 1];
			ans += arr_a[i] + arr_b[j - 1] - arr_c[k];
			continue;
		}

		ans += arr_a[i - 1] + arr_b[j-1] + arr_c[k-1];
		ans -= arr_a[i - 1] + arr_b[j-1] + arr_c[k-1];


	}

	delete
}



int main (void)
{
	int a = 0 ,b = 0, c = 0;
	cin >> a >> b >> c ;

	int* arr_a = new int[a]();
	int* arr_b = new int[b]();
	int* arr_c = new int[c]();

	cout << w(arr_a, arr_b, arr_c);

	

	return 0;
}