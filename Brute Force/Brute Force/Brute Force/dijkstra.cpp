#include <iostream>
#include <vector>
using namespace std;
#define INF 1e9

int N, M, start;

vector<pair<int, int>> graph[100001];

bool visited[100001]; //방문
int dist[100001]; //최단거리

int getSmallestNode()
{
	int min_value = INF;
	int idx = 0; //가장 최단 거리가 짧은 노드(인덱스)

	for (int i = 1; i <= N; i++)
	{
		if (dist[i] < min_value && !visited[i])
		{
			min_value = dist[i];
			idx = i;
		}
	}

	return idx;
}

void dijkstra(int start)
{
	dist[start] = 0;
	visited[start] = true;

	for (int j = 0; j < graph[start].size(); j++) 
	{
		//각 노드마다 연결
		int adjIdx = graph[start][j].first;
		dist[adjIdx] = graph[start][j].second; //최단거리 테이블에 초기값 세팅
	}

	for (int i = 0; i < N - 1; i++)
	{
		//현재 라운드에서 최단거리를 가진 노드 반환
		int now = getSmallestNode();
		visited[now] = true;

		for (int j = 0; j < graph[now].size(); j++)
		{
			int cost = dist[now] + graph[now][j].second; //현재 최단거리 노드를 경유해서 가는 거리
			if (cost < dist[graph[now][j].first]) {
				//다이렉트로 쭉 가는 거리보다 작으면 갱신 
				dist[graph[now][j].first] = cost;
			}
		}
	}
}

int main(int argc,char **argv)
{
	//N: 노드 M: 간선
	cin >> N >> M >> start;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}

	//최단 거리 테이블을 모두 무한으로 초기화
	fill_n(dist, 100001, INF);

	dijkstra(start);

    //모든 노드로 가기 위한 최단 거리를 출력
	for (int i = 1; i <= N; i++) {
		//도달할 수 없는 경우, 무한(INFINITY)이라고 출력
		if (dist[i] == INF) {
			cout << "INFINITY" << '\n';
		}
		else {
			//도달할 수 있는 경우 거리를 출력
			cout << dist[i] << '\n';
		}
	}

	return 0;
}