#include <iostream>
#include <algorithm>
using namespace std;

//n���� 5�� �μ� ������ ����� ���ϴ� �Լ�
int func(int n,int x) {
	
	int num = 0;

	for (long long i = x; i <= n; i *= x) {
		num += n / i;
	}
	
	return num;
}

//1676_re�� ����
//https://j3sung.tistory.com/235 ����
int main(int argc, char** argv)
{
	//nCr = n! / ((n-r!) * r!)
	//5�� ����� �μ��� ������ �����ص�, ���ָ� �ȴ�.
	//���ڸ� 0�� �Ƿ��� 10�� ���ϸ� �Ǵµ�, 2*5�̹Ƿ� min(2�� �μ�����,5�� �μ�����)�� ���Ѵ�.
	//������ ���丮�� Ư���� 5�� �μ������� 2�� �μ��������� �׻� �����ϱ� 5�� �μ������� ���ϸ� �ȴ�.
	//..�� Ʋ���� . n! - n-r! �̷��� ���ִϱ� � �μ��� �� ������ ���� �Ѵ� ���ϴ� �� ����. �Ѵٱ��ؼ� min�ϴϱ� ����

	int n, m;
	int five = 0;
	int two = 0;

	cin >> n >> m;

	five = (func(n,5) - func(n - m,5) - func(m,5));
	two = (func(n, 2) - func(n - m, 2) - func(m, 2));

	cout << min(five, two) << endl;


	return 0;
}