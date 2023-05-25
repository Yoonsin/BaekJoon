#include <iostream>
#include <vector>
#define INF 1e9
#define MAX 100001 //���� �̰Ͷ����� ������
using namespace std;

vector<pair<int, int>> graph[MAX]; //ex) v[1][2].first = 3 .second = 5 -> 1����忡�� 3������ ���µ� 5 �ڽ�Ʈ�� �ɸ���.  
bool visited[MAX];
int dist[MAX]; //�ִܰŸ��� ����ִ� �迭 ex) dist[3] ���� ��忡�� 3�� ���� ���µ� �ɸ��� �ּ� �ڽ�Ʈ
int E, N; //E : ���� N : ���
int FindMinNode(int now)
{
	//���� ��忡�� ���� �ִܰŸ��� ��� ��ȣ ã�� ��ȯ
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
	cin >> E >> N >> start; //���� ��� ���۳���ȣ

	for (int i = 0; i < E; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		if (b > N) { i = i - 1; continue; }
		graph[a].push_back(make_pair(b, cost));
	}

	fill_n(dist, MAX, INF); //�ϴ� �Ÿ� �迭 ���δ� �������� �ʱ�ȭ

	//���� ��忡 �̾��� �������� �ִܰŸ� ���� �ƴϴϱ� �ٽ� �־��ֱ�
	for (int i = 0; i < graph[start].size() ; i++) {
		auto temp = graph[start][i];
		dist[temp.first] = temp.second;
	}
	visited[start] = true;

	//���������� ��� ����
	for (int i = 1; i <= N; i++) 
	{
		int minNode = FindMinNode(i);
;		//i�� ��忡 ����� ��常ŭ ����
		for (int j = 0; j < graph[minNode].size(); j++) {
			if (!visited[graph[minNode][j].first]) {
				int cost = dist[minNode] + graph[minNode][j].second;
				if (cost < dist[graph[minNode][j].first]) {
					dist[graph[minNode][j].first] = cost;
				}
			}
			//minNode�� ���� ���Ž����� �ڽ�Ʈ�� �� ���� �����ϱ� �� �湮�Ѱ�
			visited[minNode] = true;
		}
	}

	for (int i = 1; i < E; i++) {
		cout << i << " : dist " << dist[i];
	}

	return 0;
}