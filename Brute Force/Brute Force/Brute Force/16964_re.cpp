#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;

vector<int> node[MAX];
bool isVisited[MAX];
int order[MAX];
int input[MAX];
int dfs[MAX];
int depth=1;

bool comp(int a, int b)
{
	return order[a] < order[b];
}

void DFS(int n)
{
	if (isVisited[n] == true) return;

	isVisited[n] = true;
	dfs[depth++] = n;
	

	for (int i = 0; i < node[n].size(); i++)
	{
		int temp = node[n][i];
		if (isVisited[temp] == false)
		{
			DFS(temp);
		}
	}
}

int main(int argc, char** argv)
{
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++)
	{
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		int now;
		cin >> now;
		order[now] = i; //인덱스: 노드번호. 값 : 순서
		input[i] = now;
	}

	for (int i = 1; i <= n; i++) {
		sort(node[i].begin(), node[i].end(), comp);
	}

	DFS(1);

	for (int i = 1; i <= n; i++)
	{

		if (dfs[i] != input[i]) {
			cout << 0;
			return 0;
		}
	}
	cout << 1;
}