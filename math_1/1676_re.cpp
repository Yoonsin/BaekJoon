#include <iostream>
using namespace std;

//���丮���� 1~n-1 ������ ���� �� ���Ѵٴ� �� �������.
// 10�� ���ؾ� 0�� ���� -> 10�� 2x5���� ��� -> min(2,5) = 0�� ���� -> 5�� ������ �׻� 2�� �������� ���� ������ 5�� ������ ���� ��
//https://torbjorn.tistory.com/247 ����
int main(int argc, char** argv)
{
	int n;
	int cnt = 0;
	cin >> n;

	for (int i = 5; i <= n; i *= 5) {
		cnt += n / i;
	} //5�� ������ 5^2���� ������..�ݺ� 

	cout << cnt;

	return 0;
}