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

	int same[MAX]; //중복 검사 배열
	memset(same, 0, sizeof(int)*MAX);

	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;

		bool flag = false;
		for (int j = 0; j < MAX; j++) {
			if (same[j] == arr[i]) {
				flag = true;
				break;
			}
		}
		if (flag) continue;

		same[i] = arr[i];
		visited[i] = true;
		answer[depth] = arr[i];
		dfs(depth+1);
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