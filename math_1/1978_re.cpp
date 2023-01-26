#include <iostream>
#include <cmath>
using namespace std;


//1~MAX ����
//�Ҽ��� �� = false �Ҽ��� �ƴ� �� = true
void make_prime(bool(&arr)[1000], int max) //1~1000����
{
	arr[0] = true; //1�� 2�� �Ҽ��� �ƴ�
	arr[1] = true;

	for (int i = 2; i <= sqrt(max); i++) {
		if (arr[i] == true){
			continue;
		}

		for (int j = i * 2; j < max; j = j + i) {
			arr[j] = true;
		}
	}
}


int main(int argc, char** argv) 
{
	
	int t;
	int n;
	cin >> t;
	while (t--) {
		cin >> n;
		bool arr[1000];
		make_prime(arr,n );
		for (int i = 0; i < n; i++) {
			if (arr[i] == false)
				cout << i+1;
		}
	}



	return 0;
}