#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
	int n;
	cin >> n;

	if (n > 1) 
	{
		for (int i = 2; i <= n; i++) {
			while (n%i == 0)
			{
				cout << i << '\n';
				n /= i;
			}

			if (n == 1)
				break;
		}

	}

	return 0;
}