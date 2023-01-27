#include <iostream>
#include <cmath>
using namespace std;

// https://ijsilver.tistory.com/44 Âü°í
bool prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

int main(int argc, char** argv) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n = 0;
	bool flag = false;
	while (true) {
		cin >> n;
		if (n == 0)
			break;
		for (int i = 1; i < n/2; i++) 
		{
			int a = i * 2 + 1;
			int b = n - a;

			if (prime(a) && prime(b)) {
				cout << n << " = " << a << " + " << b << "\n";
				flag = true;
				break;
			}
		}

		if (!flag) {
			cout << "Goldbach's conjecture is wrong\n";
		}

	}
}