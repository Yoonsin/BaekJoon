#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//https://minyeok2ee.gitlab.io/boj/boj-2089/
//http://jynote.net/entry/C%EC%96%B8%EC%96%B4-%EC%86%8C%EC%8A%A4-%EA%B0%80%EC%9E%A5-%EA%B0%84%EB%8B%A8%ED%95%9C-2%EC%A7%84%EC%88%98-%EC%B6%9C%EB%A0%A5-%EC%86%8C%EC%8A%A4

int main(int argc, char** argv)
{
	int n;
	cin >> n;

	if (n == 0)
	{
		cout << "0\n";
		return 0;
	}

	string str;
	while (n != 0)
	{
		if (n % -2 == 0)
		{
			str += "0";
			n /= -2;
		}
		else {
			str += "1";
			n = (n - 1) / -2;
		}
	}

	reverse(str.begin(), str.end());

	cout << str;

	return 0;
}