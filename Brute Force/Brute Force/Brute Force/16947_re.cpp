#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 3000+1
using namespace std;

int N;
bool isVisited[MAX];
bool isCycle;
bool CycleStation[MAX];
vector<int> Station[MAX];


void DFS(int cur, int start, int line)
{
	if (cur == start && line >= 2)
	{
		isCycle = true;
		return;
	}

	isVisited[cur] = true;
	for (int i = 0; i < Station[cur].size(); i++)
	{


		int next = Station[cur][i];

		if (isVisited[next] == false)
		{
			//isVisited[next] = true;
			DFS(next, start, line + 1);
		}
		else
		{
			if (next == start && line >= 2) {
				DFS(next, start, line + 1);
			}
		}

		if (isCycle == true) {
			return;
		}

	}
}

int BFS(int a)
{
	memset(isVisited, false, sizeof(isVisited));
	queue<pair<int,int>> q;
	q.push(make_pair(a, 0));
	isVisited[a] = true;

	while (!q.empty())
	{
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		
		if (CycleStation[cur]) {
			//cout << cnt << '\n';
			return cnt;
		}

		for (int i = 0; i < Station[cur].size(); i++)
		{
			int next = Station[cur][i];
			if (isVisited[next] == false)
			{
				
				q.push(make_pair(next,cnt+1));
				isVisited[next] = true;
				
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
		isCycle = false;
		int startStation = i;
		DFS(i, startStation, 0);

		if (isCycle == true) {
			CycleStation[i] = true;
		}
	}

	vector<int> answer;

	for (int i = 1; i <= N; i++)
	{
		if (CycleStation[i] == true) {
			answer.push_back(0);
			continue;
		}

		answer.push_back(BFS(i));
	}

	for (int i = 0; i < N; i++)
	{
		cout << answer[i] << " ";
	}
	cout << '\n';

	return 0;



}