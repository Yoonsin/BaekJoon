#include <iostream>
#include <string>
#define MAX 1000000
using namespace std;

int main(int argc, char** argv)
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	if (a <= MAX && b <= MAX && c <= MAX && d <= MAX) {
		cout << stoll (to_string(a) + to_string(b)) + stoll(to_string(c) + to_string(d));
	}

	return 0;
}