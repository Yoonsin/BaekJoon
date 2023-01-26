#include <iostream>
using namespace std;

int gcd(int a, int b) {
	while (b>0)
	{
		int tmp = a;
		a = b;
		b = tmp % b;
	}

	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}


int main(int argc, char** argv) 
{
	int t, a, b;
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		cout << lcm(a,b) << endl;
	}

	return 0;
}