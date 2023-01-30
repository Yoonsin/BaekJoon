#include <iostream>
#include <cstdlib>
using namespace std;
//1000000000 10^9 -> 10¾ï

long long gcd(long long a, long long b)
{

	while (b != 0) {
		long long tmp = a;
		a = b;
		b = tmp % b;
	}
	
	return a;
}

int main(int argc, char** argv)
{
	int n;
	long long s;
	long long d;
	
	
	cin >> n >> s;
	long long *arr = new long long[n];
	
	for (int i = 0; i < n; i++)
	{
		long long num;
		cin >> num;
		arr[i] = abs(num - s);
	}

	if (n != 1) {
		d = gcd(arr[0], arr[1]);

		for (int i = 2; i < n; i++)
		{
			d = gcd(d, arr[i]);
		}
	}
	else
	{
		d = arr[0];
	}
	

	cout << d;
		
	return 0;
}