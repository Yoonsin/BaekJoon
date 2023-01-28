#include <iostream>
using namespace std;

int factorial(int a) {
	//4! -> 4x 3! -> 3x2!-> 2x1! -> 1!-> 1
	if (a == 1 || a==0)
		return 1;
	else
		return a * factorial(a - 1);
}

int main(int argc, char** argv)
{
	int n;
	cin >> n;
	cout << factorial(n);

	return 0;
}