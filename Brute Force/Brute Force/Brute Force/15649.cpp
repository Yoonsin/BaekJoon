#include <iostream>
#define MAX 8
using namespace std;

int n,m;
int ans[MAX];
bool visited[MAX];
 
void dfs(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			ans[depth] = i+1;
			dfs(depth+1);
			visited[i] = false;
		}
	}
}


int main(int argc, char** argv) 
{
	cin >> n >> m;
	
	dfs(0);

	return 0;
}