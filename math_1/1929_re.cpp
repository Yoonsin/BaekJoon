#include <iostream>
#include <cmath>
using namespace std;

//1929.cpp�� �˰������� Ǯ�� �ð��ʰ�. 
// https://st-lab.tistory.com/80 ����
//������ + �����佺�׳׽��� ü�� Ǯ��

void get_prime(bool* (&arr),int n) {

	//true �Ҽ��ƴ�, //false �Ҽ�.

	arr[0] = true;
	arr[1] = true;

	for (int i = 2; i <= sqrt(n + 1); i++) {
		if (arr[i]) continue;
		for (int j = i * i; j < n + 1; j += i) {
			arr[j] = true;
		}
	}
}

int main(int argc, char** argv) 
{
	int m, n;
	cin >> m >> n;
	bool* arr = new bool[n + 1];
	for (int i = 0; i < n + 1; i++) {
		arr[i] = false;
	}
	get_prime(arr,n);

	for (int i = m; i <= n; i++)
	{
		if (!arr[i])
			cout << i << '\n';
	}


	return 0;
}