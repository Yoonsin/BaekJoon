#include <iostream>
#include <vector>
#define MAX 2000
using namespace std;

//https://yabmoons.tistory.com/114 ����

int n, m; //n : ���(���) �� m: ģ�� ����(����) ��
int map[MAX][MAX]; //��� �� ���� �̾��� �ִ��� �Ǵ��� �迭
vector<int> v[MAX];
bool isVisited[MAX]; //��� �湮 �ߴ��� ����
bool ans; //������ �ش��ϴ� ģ�����谡 �ִ��� ����
void dfs(int idx, int depth)
{
	if (depth == 4)
	{
		ans = true;
		return;
	}

	for (int i = 0; i < v[idx].size(); i++)
	{
		if (ans)return;

		int next = v[idx][i];
		if (isVisited[next] == false)
		{
			isVisited[next] = true;
			dfs(next, depth + 1);
			isVisited[next] = false;

		}
	}
}

int main(int argc, char** argv)
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		
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