#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 3000+1
using namespace std;

int N;
bool Cycle;
bool isVisited[MAX];
bool Check_Cycle_Station[MAX];
vector<int> Station[MAX];

void DFS(int Cur, int Start, int line) //현재역, 시작역, 경로의 수
{
	if (Cur == Start && line >= 2)
	{
		Cycle = true;
		return;
	}

	isVisited[Cur] = true;
	for (int i = 0; i < Station[Cur].size(); i++) //연결되어있는 모든역...
	{
		int Next = Station[Cur][i]; //연결된 역
		if (isVisited[Next] == false)
		{
			DFS(Next, Start, line + 1);
		}
		else {
			//현재 노드에 연결된 노드가 시작 역이라면
			if (Next == Start && line >= 2) {
				DFS(Next, Start, line+1); //순환선이므로 방문해주기
			}
		
		}

		if (Cycle == true) return; //이미 순환선 있다고 판명나면 탐색해줄 필요 없음
	}


}

int BFS(int a)
{
	memset(isVisited, false, sizeof(isVisited));
	queue<pair<int, int>> q;
	q.push(make_pair(a, 0));
	isVisited[a] = true;

	while (!q.empty())
	{
		int cur = q.front().first; //방문 노드 이름
		int cnt = q.front().second; //순환선과의 거리
		q.pop();

		if (Check_Cycle_Station[cur] == true) return cnt; //순환선이면 cnt 반환

		for (int i = 0; i < Station[cur].size(); i++)
		{
			int next = Station[cur][i];
			if (isVisited[next] == false)
			{
				isVisited[next] = true;
				q.push(make_pair(next, cnt + 1));
			}
		}
	}



}



int main(int argc, char** argv)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		Station[a].push_back(b);
		Station[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		memset(isVisited, false, sizeof(isVisited));
		Cycle = false;

		int Start_Station = i;
		DFS(i, Start_Station, 0);

		if (Cycle == true)
		{
			Check_Cycle_Station[i] = true; //i번 노드는 순환선에 있다.
		}
	}

	vector<int> Answer;
	for (int i = 1; i <= N; i++)
	{
		if (Check_Cycle_Station[i] == true)
		{
			Answer.push_back(0); //순환선에 있는 역은 순환선과 거리가 0
			continue;
		}

		Answer.push_back(BFS(i));
	}

	for (int i = 0; i < Answer.size(); i++)
	{
		cout << Answer[i] << " ";
	}
	cout << '\n';


	return 0;
}