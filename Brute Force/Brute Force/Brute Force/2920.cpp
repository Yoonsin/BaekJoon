#include <iostream>
#define MAX 8
using namespace std;


int main(int argc, char** argv) {
	
	int asc=0, des=0;

	for (int i = 0; i < MAX; i++) {
		int n;
		cin >> n;
		if (n == i + 1) { //i�� 0���� �����ϹǷ� + 1 ���ֱ�
			asc++; 
		}
		else if (n == MAX - i) {
			des++;
		}
	}

	if (asc == MAX) {
		cout << "ascending";
	}
	else if (des == MAX) {
		cout << "descending";
	}
	else {
		cout << "mixed";
	}

	
	return 0;
}