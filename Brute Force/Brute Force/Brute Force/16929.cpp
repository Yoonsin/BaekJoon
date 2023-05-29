#include <iostream>
#include <string>
#define MAX 50
using namespace std;

char dot[MAX][MAX];
char cycle[MAX * MAX];
int isVisited[MAX][MAX];
int N, M; // N : row,y M: col,x
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool flag;
int start_x, start_y;

void dfs(int depth,int x,int y) //x,y는 depth-1의 x,y
{
	if (flag == true)return;

	//cout << "depth :"<<depth << " x: " << x << " y: "<< y << '\n';

	for (int i = 0; i < 4; i++)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];

		if (tx >= 0 && ty >= 0 && tx < M && ty < N) {

			//사이클 조건
			if (isVisited[ty][tx] !=0 && start_x == tx && start_y == ty && depth > 2) {
				flag = true;
				return;
			}


			if (isVisited[ty][tx] != 0) continue;
			if (depth > 0 && cycle[depth - 1] == dot[ty][tx]) {
                
				cycle[depth] = dot[ty][tx];
				isVisited[ty][tx] = 1;
				dfs(depth + 1, tx, ty);
				isVisited[ty][tx] = 0;

			}
		}

	}
}

int main(int argc, char** argv)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			dot[i][j] = s[j];
		}
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) {
			start_x = j; start_y = i;

			isVisited[i][j] = 1;
			cycle[0] = dot[i][j];
			dfs(1,j,i);
			isVisited[i][j] = 0;
		}
	}

	

	if (flag) { cout << "Yes"; }
	else { cout << "No"; }

}