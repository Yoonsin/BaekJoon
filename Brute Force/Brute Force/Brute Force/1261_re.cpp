#include <cstdio>
#include <iostream>
#include <queue>
#define MAX 100
using namespace std;

int n, m, ans;
int map[MAX][MAX];
int dist[MAX][MAX];
int dx[] = { 1,0,0,-1 };
int dy[] = { 0,1,-1,0 };

void dijkstra() {
	priority_queue<pair<int, pair<int, int>>> pque;
	pque.push({ 0,{0,0} }); //cost [x,y] 
	dist[0][0] = 0;

	while (!pque.empty())
	{
		auto cur = pque.top(); pque.pop();
		int cost = -cur.first;
		int x = cur.second.first;
		int y = cur.second.second;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx <= n && ny <= m) {
				if (dist[nx][ny] > dist[x][y] + map[nx][ny]) {
					dist[nx][ny] = dist[x][y] + map[nx][ny];
					pque.push({ -dist[nx][ny],{nx,ny} });  //마이너스 붙이면 최대힙으로 최소힙 효과를 낼 수 있음
				}
			}
		}
	}

	return;
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
			dist[i][j] = MAX * MAX;
		}
	}
	dijkstra();

	cout << dist[n - 1][m - 1];
	return 0;
}