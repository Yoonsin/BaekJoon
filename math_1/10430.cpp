#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int a, b, c;
	cin >> a >> b >> c;

	cout << (a + b) % c << '\n' << ((a % c) + (b % c)) % c << '\n' << (a * b) % c << '\n' << ((a % c) * (b % c)) % c;

	return 0;

}