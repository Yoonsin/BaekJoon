#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char** argv) {

	int t;
	int cnt = 0;
	cin >> t;

	while (t--) {
		bool isPrime = false;

		int num;
		cin >> num;

		if (num == 1)
			continue;

		for (int j = 2; j <= sqrt(num); j++) 
		{
			if (num % j == 0) {
				isPrime = true;
				break;
			}
		}
		if (isPrime == false) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}