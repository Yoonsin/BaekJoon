#include <iostream>
#include <queue>
#include <string>
#define MAX 100
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int isVisited[MAX][MAX];
int map[MAX][MAX];
int N, M; // N == row,  M == col

void BFS()
{
	queue<pair<int, int>> q; //x,y
	q.push(make_pair(0,0));
	isVisited[0][0] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		if (x == M - 1 && y == N - 1) {
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];

			if (tx < M && ty < N && tx >= 0 && ty >= 0&& map[ty][tx] == 1) {
				if (isVisited[ty][tx] == 0)
				{
					isVisited[ty][tx] = isVisited[y][x] + 1;
					q.push(make_pair(tx, ty));
				}
			}
		}

	}

}


int main(int argc, char** argv)
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < M; j++)
		{
			map[i][j] = str[j] - '0';
		}
	}


	BFS();
	cout << isVisited[N-1][M-1];



	return 0;
}