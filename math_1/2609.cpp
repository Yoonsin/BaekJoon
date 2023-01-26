#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	//�������� 0�� �� ������ ��/�������� �ݺ��Ѵ�.
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

