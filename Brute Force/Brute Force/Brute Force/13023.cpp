#include <iostream>
#define MAX 2000
using namespace std;

int n, m; //n : 노드(사람) 수 m: 친구 관계(간선) 수
int map[MAX][MAX]; //노드 간 간선 이어져 있는지 판단할 배열
bool isVisited[MAX]; //노드 방문 했는지 여부
bool ans; //문제에 해당하는 친구관계가 있는지 여부
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