#include <iostream>
using namespace std;

//맞는 알고리즘이지만 o(n^2) 이라 2초를 훨씬 넘음.
int main(int argc, char** argv) 
{
	int m, n;
	bool flag;

	cin >> m >> n;

	for (int i = m; i <= n; i++) {
		flag = false;

		for (int j = 2; j < i; j++) {
			if ((i % j) == 0) {
				flag = true; //나누어 떨어지면 소수 아님
				break;
			}
				
		}

		if (flag == false && i != 1) {
			cout << i << '\n';
		}
	}

	return 0;
}