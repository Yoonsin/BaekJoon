#include <iostream>
#include <vector>
#define INF 1e9
#define MAX 100001 //설마 이것때문에 오류가
using namespace std;

vector<pair<int, int>> graph[MAX]; //ex) v[1][2].first = 3 .second = 5 -> 1번노드에서 3번노드로 가는데 5 코스트가 걸린다.  
bool visited[MAX];
int dist[MAX]; //최단거리가 담겨있는 배열 ex) dist[3] 시작 노드에서 3번 노드로 가는데 걸리는 최소 코스트
int E, N; //E : 간선 N : 노드
int FindMinNode(int now)
{
	//현재 노드에서 제일 최단거리인 노드 번호 찾아 반환
	int minIdx = graph[now][0].first;

	for (int i = 1; i < graph[now].size(); i++) {
		
		if (dist[graph[now][i].first] < dist[minIdx]) {
			minIdx = graph[now][i].first;
		}
	}
	return minIdx;

}

int main(int argc, char** argv)
{
	int start; 
	cin >> E >> N >> start; //간선 노드 시작노드번호

	for (int i = 0; i < E; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		if (b > N) { i = i - 1; continue; }
		graph[a].push_back(make_pair(b, cost));
	}

	fill_n(dist, MAX, INF); //일단 거리 배열 전부다 무한으로 초기화

	//시작 노드에 이어진 정점들은 최단거리 무한 아니니까 다시 넣어주기
	for (int i = 0; i < graph[start].size() ; i++) {
		auto temp = graph[start][i];
		dist[temp.first] = temp.second;
	}
	visited[start] = true;

	//순차적으로 노드 돌기
	for (int i = 1; i <= N; i++) 
	{
		int minNode = FindMinNode(i);
;		//i번 노드에 연결된 노드만큼 돌기
		for (int j = 0; j < graph[minNode].size(); j++) {
			if (!visited[graph[minNode][j].first]) {
				int cost = dist[minNode] + graph[minNode][j].second;
				if (cost < dist[graph[minNode][j].first]) {
					dist[graph[minNode][j].first] = cost;
				}
			}
			//minNode를 통해 갱신시켜줄 코스트는 다 갱신 했으니까 다 방문한것
			visited[minNode] = true;
		}
	}

	for (int i = 1; i < E; i++) {
		cout << i << " : dist " << dist[i];
	}

	return 0;
}