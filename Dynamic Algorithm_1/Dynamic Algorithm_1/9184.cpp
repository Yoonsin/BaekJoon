//동적계획법이라고 재귀를 아예 안쓰는 것은 아니다...
#include <iostream>
using namespace std;


//idea 0부터 a, 0부터 b, 0부터 c 까지 계속 값을 늘려 반복하고. / 라운드마다 들어가는 값을 이전 라운드의 값에서 찾으면 OK.
void w(int*** arr,int a_bu,int b_bu,int c_bu )
{
	int i = 0, j = 0, k = 0; //각각 0부터 a,b,c 까지 1씩 값을 늘려줄 변수
	int flag = 3;

	int a = (a_bu <= 0) ? a = -(a_bu) : a = a_bu; //0또는 음수면 절댓값으로 주고, 양수면 그대로 주기
	int b = (b_bu <= 0) ? b = -(b_bu) : b = b_bu;
	int c = (c_bu <= 0) ? c = -(c_bu) : c = c_bu;
	



	for(i=0;i<a+1;i++,a_bu++) //인덱스는 i, 비교해줄값은 a_bu이므로 따로 둔다. 이유: 배열의 인덱스는 음수가 될 수 없으므로..
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
			a *= -1;//음수면 먼저 다른 곳에 음수값 백업하고 절댓값으로 만들어 주기
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

			

		int*** arr; //매 라운드 마다 들어갈 값 저장해줄 3차원 배열

		
		arr = new int** [a + 1](); //2차원 배열을 a개 담은 3차원 배열 / 0~a(양수) -a~0(음수) 까지의 라운드를 다 담아야하기 때문에 +1. 
		for (int i = 0; i < a + 1; i++)
		{
			arr[i] = new int* [b + 1]();
			for (int j = 0; j < b + 1; j++)
			{
				arr[i][j] = new int[c + 1]();
			}
		}




		w(arr, a_bu, b_bu, c_bu); //dp함수는 a,b,c 값 그대로 주기

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