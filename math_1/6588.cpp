#include <iostream>
#include <cmath>
#define MAX 1000001
using namespace std;

//0~num 까지의 수 중 소수를 찾는 함수
//true 소수 아님 false 소수임
void make_prime(bool(&arr)[MAX], int num) 
{
	
	arr[0] = true;
	arr[1] = true;

	for (int i = 2; i <= sqrt(num); i++) {
		if (arr[i])continue;
		for (int j = i * 2; j <= num; j += i) {
			arr[j] = true;
		}
	}

}


int main(int argc, char** argv) 
{
	int n;
	int a,b;
	bool flag;

	while (true) {
		bool arr[MAX] = { false };
		flag = false;
		cin >> n;
		make_prime(arr, n);
		for (int i = 3,j=n; j-i>0; i++,j--) {
			if ((arr[i] == false) && (arr[j]== false) && (i+j == n)) 
			{
				a = i;
				b = j;
				flag = true;
				break;
			}
		}

		(flag) ? (cout << n << " = " << a << " + " << b) : (cout << "Goldbach's conjecture is wrong.");
		cout << '\n';
		
	}

	return 0;
}