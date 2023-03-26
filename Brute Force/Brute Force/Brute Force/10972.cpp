#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10000
using namespace std;

int answer[MAX]; //주어진 순열

int arr[MAX];
int arr_2[MAX];
bool isVisited[MAX];


int n;
bool flag = false;
bool flag_2 = false;

void dfs(int depth)
{
	if (flag_2) return;


	if (depth == n) {

		if (flag) {
			for (int i = 0; i < n; i++) {
				cout << arr_2[i] << ' ';
			}
			flag = false;
			flag_2 = true;
			return;
		}


		for (int i = 0; i < n; i++) {
			if (answer[i] != arr_2[i])
				break;

			if (i == n - 1) {
				//주어진 순열과 현재 순열이 같다면
				flag = true;
			}
		}
		return; 
	}

	for (int i = 0; i < n; i++) {
		
		if (isVisited[i])
			continue;
		isVisited[i] = true;
		arr_2[depth] = arr[i];
		dfs(depth+1);
		isVisited[i] = false;
	 }

}


int main(int argc, char** argv) {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> answer[i];
		arr[i] = answer[i];
	}

    sort(arr, arr + n);

	dfs(0);

	if (flag == true) {
		cout << -1;
	}

	return 0;
}