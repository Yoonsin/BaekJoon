#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int gcd(int a, int b)
{
	while (b != 0)
	{
		int tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}



int main(int argc, char** argv)
{
	int t;
	string str;

	cin >> t;
	cin.ignore();


	int n, m;
	long long sum;

	while (t--)
	{
		getline(cin, str, '\n');
		stringstream s(str);
		s >> n;

		int* arr = new int[n];
		sum = 0;

		for (int i = 0; i < n; i++) {
			s >> m;
			arr[i] = m;
		}



		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				sum += gcd(arr[i], arr[j]);
			}
		}

		cout << sum << '\n';
	}
	return 0;
}