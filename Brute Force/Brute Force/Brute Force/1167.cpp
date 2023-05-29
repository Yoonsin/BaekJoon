#include <iostream>
#include <vector>
#include <cstring>
#define MAX 100001
using namespace std;

bool isVisited[MAX];
vector<pair<int, int>> graph[MAX];
int N;
int endPoint;

// 어떤 알고리즘이 진행중일 때 그 과정값을 뽑을
//수 있는 변수를 둘수있다는 사실을 알자.
int cost;

void dfs(int root, int value) {
	for (int i = 0; i < graph[root].size(); i++) {
		auto now = graph[root][i];
		if (isVisited[now.first])continue;
		isVisited[now.first] = true;


		int nowValue = value + now.second;
		if (cost < nowValue) {
			cost = nowValue;
			endPoint = now.first;
		}
		dfs(now.first, nowValue);
	}

}

int main(int argc, char* argv[])
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		int start, dest, cost;
		cin >> start;

		while (1) {
			cin >> dest;
			if (dest == -1)break;
			cin >> cost;

			graph[start].push_back(make_pair(dest, cost));
			graph[dest].push_back(make_pair(start, cost));
		}
	}

	isVisited[1] = true;
	dfs(1, 0);
	memset(isVisited, 0, sizeof(isVisited));
	cost = 0;

	isVisited[endPoint] = true;
	dfs(endPoint, 0);
	cout << cost;



}