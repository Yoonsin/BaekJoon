#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define RED 1
#define BLUE 2
#define MAX_SIZE 20001
using namespace std;

int t, v, e;
int isVisited[MAX_SIZE];
vector<int> graph[MAX_SIZE];

void bfs(int start)
{
	queue<int> q;
	int color = RED;
	q.push(start);

	isVisited[start] = color;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (isVisited[now] == RED)
		{
			color = BLUE;
		}
		else if (isVisited[now] == BLUE)
		{
			color = RED;
		}

		int gSize = graph[now].size();
		for (int i = 0; i < gSize; i++)
		{
			int next = graph[now][i];
			if (isVisited[next] == 0)
			{
				isVisited[next] = color;

				q.push(next);
			}
			
			
		}
	}
}


int isBipartiteGraph(int v)
{
	for (int i = 1; i <= v; i++)
	{
		int gSize = graph[i].size();
		int color = isVisited[i];
		for (int j = 0; j < gSize; j++)
		{
			int next = graph[i][j];
			if (color == isVisited[next]) {
				return 0;
			}
		}
	}
	return 1;
}

int main(int argc, char** argv)
{
	cin >> t;

	while (t--)
	{
		cin >> v >> e;
		for (int i = 0; i < e; i++)
		{
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (int i = 1; i <= v; i++)
		{
			if (isVisited[i] == 0)
			{
				bfs(i);
			}
			

		}
		

		if (isBipartiteGraph(v)) cout << "YES\n";
		else cout << "NO\n";
		
		memset(isVisited, 0, sizeof(isVisited));
		for (int i = 1; i <= v; i++)
		{
			graph[i].clear();
		}
	}

	return 0;
}