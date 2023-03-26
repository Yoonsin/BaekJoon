#include <iostream>
#include <algorithm>
#include <cstdlib>
#define MAX 8
using namespace std;

int n,sum;
int arr[MAX];
int answer[MAX];
bool isVisited[MAX];

void dfs(int depth)
{
	if (depth == n) {
		int temp = 0;
		for (int i = 1; i < n; i++) {
			temp += abs(answer[i]-answer[i-1]);
		}

		sum = max(temp, sum);
	}

	for (int i = 0; i < n; i++) {
		if (isVisited[i]) continue;
		isVisited[i] = true;
		answer[depth] = arr[i];
		dfs(depth+1);
		isVisited[i] = false;

	}
}

int main(int argc, char** argv) {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dfs(0);

	cout << sum;

	return 0;
}