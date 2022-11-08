//������ȹ���̶�� ��͸� �ƿ� �Ⱦ��� ���� �ƴϴ�...
#include <iostream>
using namespace std;


//idea 0���� a, 0���� b, 0���� c ���� ��� ���� �÷� �ݺ��ϰ�. / ���帶�� ���� ���� ���� ������ ������ ã���� OK.
void w(int*** arr,int a_bu,int b_bu,int c_bu )
{
	int i = 0, j = 0, k = 0; //���� 0���� a,b,c ���� 1�� ���� �÷��� ����
	int flag = 3;

	int a = (a_bu <= 0) ? a = -(a_bu) : a = a_bu; //0�Ǵ� ������ �������� �ְ�, ����� �״�� �ֱ�
	int b = (b_bu <= 0) ? b = -(b_bu) : b = b_bu;
	int c = (c_bu <= 0) ? c = -(c_bu) : c = c_bu;
	



	for(i=0;i<a+1;i++,a_bu++) //�ε����� i, �����ٰ��� a_bu�̹Ƿ� ���� �д�. ����: �迭�� �ε����� ������ �� �� �����Ƿ�..
	{
		for (j = 0; j < b+1; j++,b_bu++)
		{
			for (k = 0; k < c+1; k++,c_bu++)
			{
				if (a_bu <= 0 || b_bu <= 0 || c_bu <= 0)
				{
					arr[i][j][k] = 1;
					continue;

				}

				if (a_bu > 20 || b_bu > 20 || c_bu > 20)
				{
					arr[i][j][k] = 1048576;
					continue;
				}

				if (a_bu < b_bu && b_bu < c_bu)
				{
					arr[i][j][k] = arr[i][j][k - 1] + arr[i][j - 1][k - 1] - arr[i][j - 1][k];
					continue;
				}

				arr[i][j][k] = arr[i - 1][j][k] + arr[i - 1][j - 1][k] + arr[i - 1][j][k - 1] - arr[i - 1][j - 1][k - 1];
				
			
			}
		}

	}

}



int main (void)
{
	while (true)
	{
		int a = 0, b = 0, c = 0;
		int a_bu = 0, b_bu = 0, c_bu = 0;
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1)
			break;

		if (a <= -50 && a >= 50)
			break;
		if (b <= -50 && b >= 50)
			break;
		if (c <= -50 && c >= 50)
			break;


		if (a < 0)
		{
			a_bu = a;
			a *= -1;//������ ���� �ٸ� ���� ������ ����ϰ� �������� ����� �ֱ�
		}
		else
		{
			a_bu = a;
		}

		if (b < 0)
		{
			b_bu = b;
			b *= -1;
		}
		else
		{
			b_bu = b;
		}

		if (c < 0)
		{
			c_bu = c;
			c *= -1;
		}
		else
		{
			c_bu = c;
		}

			

		int*** arr; //�� ���� ���� �� �� �������� 3���� �迭

		
		arr = new int** [a + 1](); //2���� �迭�� a�� ���� 3���� �迭 / 0~a(���) -a~0(����) ������ ���带 �� ��ƾ��ϱ� ������ +1. 
		for (int i = 0; i < a + 1; i++)
		{
			arr[i] = new int* [b + 1]();
			for (int j = 0; j < b + 1; j++)
			{
				arr[i][j] = new int[c + 1]();
			}
		}




		w(arr, a_bu, b_bu, c_bu); //dp�Լ��� a,b,c �� �״�� �ֱ�

		cout << "w(" << a_bu << ", " << b_bu << ", " << c_bu << ") = " << arr[a][b][c] << endl;

		
		for (int i = 0; i < a + 1; i++)
		{
			for (int j = 0; j < b + 1; j++)
			{
				delete[] arr[i][j];
			}
		}
		for (int i = 0; i < a + 1; i++)
			delete[] arr[i];

		delete[] arr;
		
	}
	

	return 0;
}