#include <iostream>
#include <algorithm>
#define MAX 10
using namespace std;

bool isVisited[MAX];
int w[MAX][MAX];
int n;
int value = 2e9;
int startIdx;

//���� https://gdlovehush.tistory.com/335
//visitIdx�� ���� �湮�� ���� �ε���
void dfs(int depth, int visitIdx, int sum) 
{
	if (depth == n) {
		if (w[visitIdx][startIdx] > 0) {
			value = min(value, sum + w[visitIdx][startIdx]);
		}
		
		return;
	}

	for (int i = 0; i < n; i++) {
		
		if (isVisited[i]) continue;
		if (w[visitIdx][i] == 0) continue;
		
		isVisited[i] = true;
	    dfs(depth + 1, i, sum + w[visitIdx][i]);
		isVisited[i] = false;
	}

}

int main(int argc, char** argv) 
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		startIdx = i;
		isVisited[i] = true;
		dfs(1, i, 0);
		isVisited[i] = false;
	}


	cout << value;

	return 0;
}