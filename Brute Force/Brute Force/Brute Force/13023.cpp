#include <iostream>
#define MAX 2000
using namespace std;

int n, m; //n : ���(���) �� m: ģ�� ����(����) ��
int map[MAX][MAX]; //��� �� ���� �̾��� �ִ��� �Ǵ��� �迭
bool isVisited[MAX]; //��� �湮 �ߴ��� ����
bool ans; //������ �ش��ϴ� ģ�����谡 �ִ��� ����
void dfs(int v, int depth)
{
	if (depth == 4)
	{
		ans = true;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (ans)return;

		if (isVisited[i] == false && ((map[i][v] == 1) || (map[v][i] == 1))) 
		{
			isVisited[i] = true;
			dfs(i, depth + 1);
			isVisited[i] = false;

		}
	}
}

int main(int argc, char** argv)
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		map[u][v] = 1;
		map[v][u] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		isVisited[i] = true;
		dfs(i, 0);
		isVisited[i] = false;
		if (ans) { break; }
	}

	cout << ans;

	return 0;
}