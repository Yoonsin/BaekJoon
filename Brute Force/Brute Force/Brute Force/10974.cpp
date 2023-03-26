#include <iostream>
#define MAX 8
using namespace std;

int answer[MAX];
bool isVisited[MAX];
int n;

void dfs(int depth) {
	if (depth == n) {
		for (int i = 0; i < depth; i++) {
			cout << answer[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (isVisited[i]) continue;

		isVisited[i] = true;
		answer[depth] = i + 1;
		dfs(depth+1);
		isVisited[i] = false;
	}
}


int main(int argc, char** argv) {
	

	cin >> n;

	dfs(0);
	
	
	
	return 0;
}