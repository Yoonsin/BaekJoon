#include <iostream>
using namespace std;

//�´� �˰��������� o(n^2) �̶� 2�ʸ� �ξ� ����.
int main(int argc, char** argv) 
{
	int m, n;
	bool flag;

	cin >> m >> n;

	for (int i = m; i <= n; i++) {
		flag = false;

		for (int j = 2; j < i; j++) {
			if ((i % j) == 0) {
				flag = true; //������ �������� �Ҽ� �ƴ�
				break;
			}
				
		}

		if (flag == false && i != 1) {
			cout << i << '\n';
		}
	}

	return 0;
}