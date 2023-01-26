#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	//나머지가 0이 될 때까지 몫/나머지를 반복한다.
	while (b > 0)
	{
		int tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;

}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);

}

int main(int argc, char** argv)
{
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << '\n' << lcm(a, b);

	return 0;
}

