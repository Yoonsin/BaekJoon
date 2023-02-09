#include <iostream>
using namespace std;

int main(void)
{
    int n;
	cin >> n;

	int* arr = new int[n+1];

	for (int i = 1; i <= n; i++)
	{
		arr[i] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		arr[i * 3] += 1;
		if(i*2 %3 != 0)
		  arr[i * 2] += 1;
		
		if((i+1)%2 == 0 || (i+1)%3 == 0)
		  arr[i + 1] += 1;
	}

	cout << arr[n];

	return 0;
}