#include <iostream>
#include <cmath>
using namespace std;

//https://minyeok2ee.gitlab.io/boj/boj-17103/ Âü°í

bool isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

int main(int argc, char** argv)
{
	int t = 0;
	cin >> t;
	
	while (t--)
	{

		int n;
		int sum = 0;
		cin >> n;

		for (int i = 2; i <= n / 2; i++) {
			 
			int a = i;
			int b = n - a;
			
			
			if (isPrime(a) && isPrime(b)) {
				sum++;
				
			}
		}

		cout << sum << '\n';
		
	}



	return 0;
}