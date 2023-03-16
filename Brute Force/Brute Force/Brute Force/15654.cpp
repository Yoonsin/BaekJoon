#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 8
using namespace std;

int answer[MAX];
vector<int> arr;
bool visited[MAX];
int m, n;

void dfs(int depth) {
	if (depth == m) {
		for (int i = 0; i < depth; i++) {
			cout << answer[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {

		if (!visited[i]) {
			visited[i] = true;
			answer[depth] = arr[i];
			dfs(depth + 1);
			visited[i] = false;
		}
		else {
			continue;
		}
		
	}


}

int main(int argc, char** argv)
{

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int n;
		cin >> n;
		arr.push_back(n);
	}
	sort(arr.begin(),arr.end() );

	dfs(0);


	return 0;
}