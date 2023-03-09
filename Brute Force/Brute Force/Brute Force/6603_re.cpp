#include <iostream>
using namespace std;

//참고 : https://sanghyu.tistory.com/58
//참고2 : https://jun-itworld.tistory.com/15
//브루트 포스(완전탐색) - DFS (비선형 구조 탐색)
int num;
int lotto[14];
int ans[6];

void dfs(int start, int depth)
{
	//종료조건
	if (depth == 6) {
		for (int i = 0; i < 6; i++) {
			cout << ans[i] << ' ';
		}
		cout << endl;
		return;
	}

	//재귀: 재귀가 return되면 다시 다음 문자에 대해 dfs
	for (int i = start; i < num; i++) {
		ans[depth] = lotto[i];
		dfs(i + 1, depth + 1);
	}
}


int main(int argc, char** argv) 
{
	while (cin >> num && num)
	{
		for (int i = 0; i < num; i++) {
			cin >> lotto[i];
		}
		dfs(0, 0);
		cout << endl;
	}

	return 0;
}