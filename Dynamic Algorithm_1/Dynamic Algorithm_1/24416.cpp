#include <iostream>
using namespace std;


//피보나치 재귀함수 VER
int fib(int n,int& cnt) { //참조에 의한 호출은 함수를 호출하는 쪽의 실인자의 공간을 공유하도록 하는 방식
	
	
	if (n == 1 || n == 2)
	{
		cnt++;
		return 1; 
		
	}
	else
	{
		return (fib(n - 1, cnt) + fib(n - 2, cnt));
	}
}

//피보나치 DP VER
void fibo(int n,int *f,int& cnt)
{
	
	f[1] = 1;
	f[2] = 1;
	for (int i = 3; i < n+1; i++)
	{
		f[n] = f[n - 1] + f[n - 2];
		cnt++;
	}
		

}

int main(void)
{
	int n = 0;

    int cnt_1 = 0;
	int cnt_2 = 0;

	int fib_ans = 0;

	cin >> n;

	int* f = new int[n+1];


	fib_ans = fib(n, cnt_1);
    fibo(n, f, cnt_2);

	cout << cnt_1 << " " << cnt_2;

	delete[] f;
	

	return 0;
}