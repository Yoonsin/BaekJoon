#include <iostream>
#define MAX 10000
using namespace std;

int number[MAX];

//https://softworking.tistory.com/230 Âü°í
bool nextPermutation(int* number, int n) {
	int i = n - 1;
	while (i > 0 && number[i - 1] > number[i])
	{
		--i;
	}

	if (i <= 0)
	{
		return false;
	}

	int j = n - 1;
	while (number[i-1]>number[j])
	{
		--j;
	}

	swap(number[i - 1], number[j]);

	for (int k = i, h = n - 1; k < h; ++k, --h)
	{
		swap(number[k], number[h]);
	}

	return true;
}


int main(int argc, char** argv)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}

	if (nextPermutation(number, n)) {
		for (int i = 0; i < n; i++) {
			cout << number[i] << ' ';
		}
		cout << '\n';
	}
	else {
		cout << -1;
	}

	return 0;
}