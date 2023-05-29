#include <iostream>
#include <vector>
#define MAX 2000
using namespace std;

//https://yabmoons.tistory.com/114 참고

int n, m; //n : 노드(사람) 수 m: 친구 관계(간선) 수
int map[MAX][MAX]; //노드 간 간선 이어져 있는지 판단할 배열
vector<int> v[MAX];
bool isVisited[MAX]; //노드 방문 했는지 여부
bool ans; //문제에 해당하는 친구관계가 있는지 여부
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