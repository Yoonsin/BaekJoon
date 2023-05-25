#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;

int graph[MAX][MAX];
int M, N; // M : col,x N : row,y
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs()
{
	queue<pair<int, int>> q; //x,y

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (graph[i][j] == 1) {
				q.push(make_pair(j, i));
			}
		}
	}

	while (q.empty() == false)
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];

			if (tx >= 0 && ty >= 0 && tx < M && ty < N) {
				if (graph[ty][tx] == 0) {
					graph[ty][tx] = graph[y][x]+1;
					q.push(make_pair(tx, ty));
				}
			}


		}
		 
	}
	
}

int main(int argc, char** argv)
{
	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> graph[i][j];
		}
	}

	bfs();

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (graph[i][j] == 0)
			{
				cout << -1;
				return 0;
			}

			if (ans < graph[i][j]) {
				ans = graph[i][j];
			}
		}
	}

	cout << ans - 1;

	return 0;
}