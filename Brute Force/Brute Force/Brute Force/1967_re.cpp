#include <iostream>
#include <vector>
#define MAX 10002
using namespace std;

vector<pair<int, int>> node[MAX];
bool isVisited[MAX] = { false, };
int result = 0;
int endPoint = 0;

void dfs(int p, int len) {
	if (isVisited[p])return;

	isVisited[p] = true;
	if (result < len) {
		result = len;
		endPoint = p;
	}

	for (int i = 0; i < node[p].size(); i++) {
		dfs(node[p][i].first, len + node[p][i].second);
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({ b,c });
		node[b].push_back({ a,c });
	}

	dfs(1, 0);

	result = 0;
	memset(isVisited, false, sizeof(isVisited));

	dfs(endPoint, 0);
	cout << result;
}