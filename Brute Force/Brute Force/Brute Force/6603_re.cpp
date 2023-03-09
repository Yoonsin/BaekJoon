#include <iostream>
using namespace std;

//���� : https://sanghyu.tistory.com/58
//����2 : https://jun-itworld.tistory.com/15
//���Ʈ ����(����Ž��) - DFS (���� ���� Ž��)
int num;
int lotto[14];
int ans[6];

void dfs(int start, int depth)
{
	//��������
	if (depth == 6) {
		for (int i = 0; i < 6; i++) {
			cout << ans[i] << ' ';
		}
		cout << endl;
		return;
	}

	//���: ��Ͱ� return�Ǹ� �ٽ� ���� ���ڿ� ���� dfs
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