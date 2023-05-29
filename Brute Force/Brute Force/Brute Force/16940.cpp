#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100000+1
using namespace std;

vector<int> v_2[MAX]; // 인덱스는 깊이.  값은 같은 깊이에 있는 노드 번호들.

vector<int> v[MAX]; // 인덱스는 노드 번호. 값은 인덱스 번호의 노드와 연결되어있는 노드 번호들 

bool isVisited[MAX];

int N;  // 정점 개수

int input[MAX]; //입력으로 주어진 BFS 방문 순서

void bfs()
{
	queue<pair<int, int>> q; //노드번호, 깊이

	//시작정점 푸시
	q.push(make_pair(1, 0));
	isVisited[1] = true;

	//마지막 깊이 체크해줄 변수
	int last_depth = 0;

	while (!q.empty())
	{
		int node = q.front().first;
		int depth = q.front().second;
		q.pop();

		v_2[depth].push_back(node);
		last_depth = depth;

		//현재 노드와 연결된 노드들 전부 탐색
		for (int i = 0; i < v[node].size(); i++)
		{
			int next = v[node][i];
			if (!isVisited[next]) {
				q.push(make_pair(next, depth + 1));
				isVisited[next] = true;
			}
		}

	}

	int start = 0;
	int end = 0;

	for (int i = 0; i <= last_depth; i++)
	{
		//v_2[i]의 사이즈가 곧 구간.
		//구간의 시작과 끝을 알고. input 값에서 특정구간을 확인했을 때 그 값이 없다면 틀린것
		end = start + v_2[i].size() -1 ;

		//input 배열과 v_2 배열의 값을 파악해주는 집합
		set<int> s;
		for (int j = 0; j < v_2[i].size(); j++)
		{
			int now = v_2[i][j];
			s.insert(now);
		}

		//큐에서 값을 꺼내는 순서가 오름차순또는 같은순인지 파악해주는 배열
		vector<int> v_3; 

		for (int j = start; j <= end; j++)
		{
			//만약 구간에 값이 없다면
			if (s.find(input[j]) == s.end())
			{
				cout << 0;
				return;
			}
			else {
				//구간에 값이 있어도
				//큐에서 값을 꺼내는 순서가 잘못됐으면 그것도 틀린것.
				if (i >= 1) {
					//이전 깊이의 구간
					int pre_start = start - v_2[i-1].size();
					int pre_end = start - 1;

					for (int x = pre_start; x <= pre_end; x++)
					{
						int now = input[x];

						//현재 노드가 이전 구간 몇번째 노드와 이어져 있는지 순서 파악. 
						if (find(v[now].begin(), v[now].end(), input[j]) != v[now].end()) {
							v_3.push_back(x);
						}
					}

				}
			}
		}

		/* Print
		cout << "depth " << i << '\n';
		for (int j = 0; j < v_3.size(); j++) {
			
			cout << v_3[j] << ' ';
		}
		cout << '\n';
		*/

		for (int j = 1; j < v_3.size(); j++)
		{
			//큐에서 값을 꺼내는 순서가 오름차순이나 같지 않으면 틀린 것.
			if (v_3[j - 1] > v_3[j]) {
				cout << 0;
				return;
			}
		}

		start = end + 1;
	}

	//구간 전부에 값이 있다==올바른 값이다.
	cout << 1;
	

}

int main(int argc, char* argv[])
{
	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);

	}

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		input[i] = a;

	}

	if (input[0] != 1) {
		cout << 0;
		return 0;
	}

	bfs();


}

