#include <iostream>
using namespace std;

//�����ϰ� ��� ������ ���� �� �迭�� ���ڴ� ������ NO.. ��Ȯ�� ������ ��������. ������ȹ���� ��͸� �� �� �ִ�.

int ans[21][21][21];

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	else if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);
	else if (ans[a][b][c] != 0) return ans[a][b][c];
	else if (a < b && b < c)
		ans[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else
		ans[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	
	return ans[a][b][c];

}

int main(void)
{
	int a=0, b=0, c=0;
	while (true)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) <<endl;
	}
	

	return 0;
}