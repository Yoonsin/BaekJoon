#include <iostream>
#include <algorithm>
using namespace std;

//n에서 5의 인수 개수가 몇개인지 구하는 함수
int func(int n,int x) {
	
	int num = 0;

	for (long long i = x; i <= n; i *= x) {
		num += n / i;
	}
	
	return num;
}

//1676_re도 참고
//https://j3sung.tistory.com/235 참고
int main(int argc, char** argv)
{
	//nCr = n! / ((n-r!) * r!)
	//5의 배수인 인수의 개수를 세어준뒤, 빼주면 된다.
	//끝자리 0이 되려면 10을 곱하면 되는데, 2*5이므로 min(2의 인수개수,5의 인수개수)로 구한다.
	//하지만 팩토리얼 특성상 5의 인수개수가 2의 인수개수보다 항상 적으니까 5의 인수개수만 구하면 된다.
	//..는 틀림ㅋ . n! - n-r! 이렇게 빼주니까 어떤 인수가 더 적을지 몰라서 둘다 구하는 것 같다. 둘다구해서 min하니까 맞음

	int n, m;
	int five = 0;
	int two = 0;

	cin >> n >> m;

	five = (func(n,5) - func(n - m,5) - func(m,5));
	two = (func(n, 2) - func(n - m, 2) - func(m, 2));

	cout << min(five, two) << endl;


	return 0;
}