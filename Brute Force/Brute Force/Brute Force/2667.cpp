#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define LIST_MAX 25*25
#define NODE_MAX 25*25
using namespace std;

int N;
vector<int> apartList[LIST_MAX];
vector<int> graph;
bool isVisited[NODE_MAX];
int apartCnt;

void dfs(int start)
{
	//현재 노드 방문처리
	isVisited[start] = true;
	apartList[apartCnt].push_back(start);


	if (start + N < graph.size())
	{
		if (graph[start] == graph[start + N]) //아래쪽에도 집있으면
		{
			if (isVisited[start + N] == false) {
				dfs(start + N);
			}

			//탐색
		}
	}

	if (start - N >= 0)
	{
		if (graph[start] == graph[start - N]) //위쪽에도 집 있으면
		{
			if (isVisited[start - N] == false) {
				dfs(start - N); //탐색
			}

		}
	}
	
	
	if (start + 1 < graph.size() && ((start+1)%N !=0))
	{
		if (graph[start] == graph[start + 1]) //오른쪽에도 집있으면
		{
			if (isVisited[start + 1] == false)
			{
				dfs(start + 1);
			} //탐색
		}
	}

	if (start != 0 && ((start-1)/N == start/N))
	{
		if (graph[start] == graph[start - 1]) //왼쪽에도 집 있으면
		{
			if (isVisited[start - 1] == false)
			{
				dfs(start - 1);
				//탐색
			}
		}
	}
	



	return;
}



int main(int argc, char** argv)
{
	
	cin >> N;

	
	for(int i=0;i<N;i++)
	{
		string row;
		cin >> row;
		for (int j = 0; j < row.size(); j++)
		{
			int apart = row[j] - '0';
			graph.push_back(apart);
		}
	}

	for (int i = 0; i < graph.size(); i++)
	{
		int now = graph[i]; //i는 집의 인덱스, now는 집의 유무
		int gSize = apartList[apartCnt].size();
		if (now == 1) {
			if (isVisited[i] == false)
			{
				dfs(i);
			}
		}

		if(gSize != apartList[apartCnt].size())
		{
			apartCnt++;
		}
		
	}

	cout << apartCnt<< '\n';
	
	vector<int> apartSortNum;
	for (int i = 0; i < apartCnt; i++)
	{
		apartSortNum.push_back(apartList[i].size());
	}

	sort(apartSortNum.begin(),apartSortNum.end());
	for (int i = 0; i < apartSortNum.size(); i++)
	{
		cout << apartSortNum[i] << '\n';
	}
	
	return 0;
}