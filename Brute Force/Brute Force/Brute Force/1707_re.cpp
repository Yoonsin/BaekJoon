#include <iostream>
#include <vector>
#include <cstring>
#define MAX_SIZE 20000+1
#define RED 1
#define BLUE 2
using namespace std;


int K, V, E; 
vector<int> graph[MAX_SIZE];
int isVisited[MAX_SIZE];

//https://jdselectron.tistory.com/51 じい 酒抚促款 内靛老技..

void dfs(int start)
{
	if (!isVisited[start])isVisited[start] = RED;

	int gSize = graph[start].size();

	for (int i = 0; i < gSize; i++)
	{
		int next = graph[start][i];
		if (!isVisited[next]) {
			if (isVisited[start] == RED) {
				isVisited[next] = BLUE;
			}
			else if (isVisited[start] == BLUE) {
				isVisited[next] = RED;
			}
			dfs(next);
		}
	}

}

bool isBipartiteGraph()
{
	for (int i = 1; i <= V; i++) {
		int gSize = graph[i].size();
		for (int j = 0; j < gSize; j++) {
			int next = graph[i][j];
			if (isVisited[i] == isVisited[next]) {
				return 0;
			}
		}
	}
	return 1;
}


int main(int argc, char** argv)
{
	cin >> K;
	while (K--)
	{
		cin >> V >> E;

		for (int i = 0; i < E; i++)
		{
			int f, s;
			cin >> f >> s;
			graph[f].push_back(s);
			graph[s].push_back(f);
		}

		for (int i = 1; i <= V; i++)
		{
			if (!isVisited[i]) {
				dfs(i);
			}
		}

		if (isBipartiteGraph()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}

		for (int i = 0; i <= V; i++) {
			graph[i].clear();
		}
		memset(isVisited, false, sizeof(isVisited));

	}


	return 0;
}