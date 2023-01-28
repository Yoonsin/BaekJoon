#include <iostream>
using namespace std;

//팩토리얼은 1~n-1 까지의 수를 다 곱한다는 걸 기억하자.
// 10을 곱해야 0이 나옴 -> 10은 2x5임을 기억 -> min(2,5) = 0의 개수 -> 5의 개수가 항상 2의 개수보다 적기 때문에 5의 개수만 세면 됨
//https://torbjorn.tistory.com/247 참고
int main(int argc, char** argv)
{
	int n;
	int cnt = 0;
	cin >> n;

	for (int i = 5; i <= n; i *= 5) {
		cnt += n / i;
	} //5로 나누고 5^2으로 나누고..반복 

	cout << cnt;

	return 0;
}