#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 8
using namespace std;

int arr[MAX];
int answer[MAX];
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

	int before = 0;

	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		if (before == arr[i]) continue;
		visited[i] = true;
		answer[depth] = arr[i];
		before = answer[depth];
		dfs(depth + 1);
		visited[i] = false;
	}

}


int main(int argc, char* argv[]) {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n); //오름차순으로 정렬

	dfs(0);
	return 0;
}