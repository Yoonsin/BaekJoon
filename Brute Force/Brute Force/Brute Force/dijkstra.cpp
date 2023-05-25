#include <iostream>
#include <vector>
using namespace std;
#define INF 1e9

int N, M, start;

vector<pair<int, int>> graph[100001];

bool visited[100001]; //�湮
int dist[100001]; //�ִܰŸ�

int getSmallestNode()
{
	int min_value = INF;
	int idx = 0; //���� �ִ� �Ÿ��� ª�� ���(�ε���)

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
		//�� ��帶�� ����
		int adjIdx = graph[start][j].first;
		dist[adjIdx] = graph[start][j].second; //�ִܰŸ� ���̺� �ʱⰪ ����
	}

	for (int i = 0; i < N - 1; i++)
	{
		//���� ���忡�� �ִܰŸ��� ���� ��� ��ȯ
		int now = getSmallestNode();
		visited[now] = true;

		for (int j = 0; j < graph[now].size(); j++)
		{
			int cost = dist[now] + graph[now][j].second; //���� �ִܰŸ� ��带 �����ؼ� ���� �Ÿ�
			if (cost < dist[graph[now][j].first]) {
				//���̷�Ʈ�� �� ���� �Ÿ����� ������ ���� 
				dist[graph[now][j].first] = cost;
			}
		}
	}
}

int main(int argc,char **argv)
{
	//N: ��� M: ����
	cin >> N >> M >> start;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}

	//�ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ
	fill_n(dist, 100001, INF);

	dijkstra(start);

    //��� ���� ���� ���� �ִ� �Ÿ��� ���
	for (int i = 1; i <= N; i++) {
		//������ �� ���� ���, ����(INFINITY)�̶�� ���
		if (dist[i] == INF) {
			cout << "INFINITY" << '\n';
		}
		else {
			//������ �� �ִ� ��� �Ÿ��� ���
			cout << dist[i] << '\n';
		}
	}

	return 0;
}