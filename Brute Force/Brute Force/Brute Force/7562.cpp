#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
#define MAX 300
using namespace std;

int board[MAX][MAX];
int N;
int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[8] = { -1,-2,-2,-1,1,2,2,1 };

int start_x, start_y;
int dest_x, dest_y;
int ans = MAX+1;


void bfs()
{

	queue<pair<int, int>> q;
	q.push(make_pair(start_x, start_y));
	board[start_y][start_x] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];

			if (tx >= 0 && ty >= 00 && tx < N && ty < N)
			{
				if (board[ty][tx] == 0)
				{
					q.push(make_pair(tx, ty));
					board[ty][tx] = board[y][x] + 1;

					if (tx == dest_x && ty == dest_y) {
						ans = min(ans, board[ty][tx]);
					}
				}
			}
		}

	}


}

int main(int argc, char** argv)
{
	int T;
	cin >> T;

	while (T--)
	{
		cin >> N;
		cin >> start_x >> start_y;
		cin >> dest_x >> dest_y;

		
		/*
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if ((i == start_y && j == start_x) || (i == dest_y && j == dest_x)) {
					cout << " * ";
				}
				else {
					cout <<' ' << board[i][j] << ' ';
				}
				
			}
			cout << '\n';
		}
		cout << '\n';*/
		

		//만약 시작점과 도착점이 같다면
        //bfs 해줄 필요없음
		if (start_x == dest_x && start_y == dest_y)
		{
			cout << 0 << '\n';
		}
		else {
			bfs();
			cout << ans - 1 << '\n';
			
		}

		//print
		/*
		cout << '\n';
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << ' ' << board[i][j] << ' ';
			}
			cout << '\n';
		}*/
	


		//reset
	
		memset(board, 0,sizeof(board[0][0])*MAX*MAX);
		
		ans = MAX+1;
	}

	return 0;
}