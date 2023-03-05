#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char** argv) 
{
	int n;
	cin >> n;
	
	int i = 1; //자릿수
	int answer = 0; //1~n까지의 수를 이어서 쓴 수의 자릿수
	while (true)
	{
		if (n < (pow(10, i)-1) ) {
			//n은 i자리 수
			//ex) i:3 n:120 일 때 120 < 10^3-1 -> 120 < 999
			answer += i * ((n - pow(10, (i - 1)))+1);
			break;
		}
		else {
			answer += i * (pow(10, (i - 1)) * 9);
		}

		i++;
	}

	cout << answer;
	return 0;
}