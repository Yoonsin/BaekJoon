#include <iostream>
#include <string>
using namespace std;

long long fac(long long n)
{
	if (n <= 1)
		return 1;
	else
		return n * fac(n-1);
}

int main(int argc, char** argv) 
{
	long long n;
	int cnt = 0;
	string result;
	cin >> n;
	result = to_string(fac(n));

	
	for (int i = result.size()-1; i >= 0 ; i--) {
		if (result[i] == '0')
			cnt++;
		else
			break;
	}

	cout << cnt;
	
	return 0;

}