#include <iostream>
#include <queue>
#include <string>
#define MAX 10001
using namespace std;

bool isWall[MAX];
bool isVisited[MAX][2]; //[노드번호][벽 여부]
int N, M;
int Cracking[MAX];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int ans = MAX + 1;

void bfs()
{
	//((x,y),벽 부순 횟수)
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(1, 1), 0));
	Cracking[1] = 0;
	isVisited[1][isWall[1]] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cracking = q.front().second;
		q.pop();

		

		if (x == M && y == N) {

			ans = min(ans, Cracking[x*y]);
		}


		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i];
			int ty = y + dy[i];


			if (tx >= 1 && ty >= 1 && tx <= M && ty <= N) {

				int node = N * (ty - 1) + tx;
				if (isVisited[node][isWall[node]] == false) {
					if (isWall[node] == 1)
					{
						//벽
						q.push(make_pair(make_pair(tx, ty), cracking + 1));
						isVisited[node][isWall[node]] = 1;
						isWall[node] = 0;
						isVisited[node][isWall[node]] = 1;
						Cracking[node] = cracking + 1;
					}
					else {
						//빈방
						q.push(make_pair(make_pair(tx, ty), cracking));
						isVisited[node][isWall[node]] = 1;
						Cracking[node] = cracking;
					}


				}
				else {
					//만약 다음 노드를이미 방문했어도
					//현재 노드의 cracking을 넣었을 때 더 작을 것 같으면
					//갱신 시켜주기
					//이미 방문했으면 당연히 벽 뽀개진상태
					if (cracking < Cracking[node]) {
						Cracking[node] = cracking;
						//cout << Cracking[node] << '\n';
						//q.push(make_pair(make_pair(tx, ty), cracking));

					}

				}

			}
		}

	}

}

int main(int argc, char* argv[])
{
	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < str.length(); j++)
		{
			int a, node;
			a = str[j] - '0';
			node = j + 1 + N * (i - 1);
			isWall[node] = a;
		}
	}

	bfs();
	cout << ans;
	//0 :빈방 1 :벽


	cout << '\n';
	for (int i = 1; i <= N * M; i++)
	{
		cout << isWall[i];
		if (i % M == 0)cout << '\n';
	}

	//cout << bfs();
}