#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001

//참고 : https://scarlettb.tistory.com/76
int N, M, V; //정점개수, 간선개수, 시작정점
int map[MAX][MAX]; //인접 행렬 그래프
bool isVisited[MAX]; //정점 방문 여부
queue<int> q;

void reset()
{
	for (int i = 0; i <= N; i++)
	{
		isVisited[i] = false;
	}
}

void dfs(int v)
{
	isVisited[v] = true;
	cout << v << " ";

	for (int i = 1; i <= N; i++)
	{
		if (map[v][i] == 1 && isVisited[i] == false) {
			dfs(i);
		}
	}

}


void bfs(int v)
{
	q.push(v);
	isVisited[v] = true;
	cout << v << " ";

	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (int w = 1; w <= N; w++) {
			if (map[v][w] == 1 && isVisited[w] == false) {
				q.push(w);
				isVisited[w] = true;
				cout << w << " ";
			}
		}
	}

}

int main(int argc, char** argv)
{
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	dfs(V);

	cout << '\n';

	reset();
	bfs(V);

	return 0;
}