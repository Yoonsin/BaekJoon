//참고 https://yabmoons.tistory.com/74
#include <iostream>
#include <queue>
#define MAX 2000
using namespace std;

int S;
bool isVisited[MAX][MAX];
int bfs()
{
	queue<pair<pair<int, int>,int>> q;
	q.push(make_pair(make_pair(1, 0), 0)); //처음 화면의 이모티콘 개수, 시간 => (1개, 0초)
	isVisited[1][0] = true;


	while (q.empty() == 0) {
		int node = q.front().first.first;
		int clip = q.front().first.second;
		int depth = q.front().second;
		
		q.pop();


		if (node == S) {
			return depth;
		}

		if (node > 0 && node < MAX)
		{
			if (isVisited[node][node] == false) {

				isVisited[node][node] = true;
				q.push(make_pair(make_pair(node,node), depth + 1));

			}
			if (isVisited[node - 1][clip] == false)
			{
				isVisited[node - 1][clip] = true;
				q.push(make_pair(make_pair(node-1, clip), depth + 1));

			}
		}

		if (clip > 0 && clip + node < MAX)
		{
			if (isVisited[node + clip][clip] == false)
			{
				isVisited[node + clip][clip] = true;
				q.push(make_pair(make_pair(node+clip, clip), depth + 1));

			}
		}

	}
}

	



int main(int argc, char** argv)
{
	cin >> S;
	cout << bfs();


	return 0;
}