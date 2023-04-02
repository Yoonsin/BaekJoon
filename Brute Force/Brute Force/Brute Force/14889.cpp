#include <iostream>
#include <cstdlib>
#include <algorithm>
#define MAX 20
using namespace std;

int value[MAX][MAX];

int answer[MAX]; //스타트팀 명단
int list[MAX]; //링크팀 명단

bool isVisited[MAX];
int n;

int minStat = 40000 + 1; 
int cnt;

void dfs(int depth, int start) 
{
	if (depth == n / 2)
	{
		int cnt1 = 0;
		int cnt2 = 0;
		
		int sum1 = 0;
		int sum2 = 0;

		//Stat 계산
		for (int i = 0; i < n; i++)
		{
			if (isVisited[i])
			{
				answer[cnt1] = i;
				cnt1++;

				

			}
			else {
				list[cnt2] = i;
				cnt2++;

			}
			
		}

		cnt1 = 0;
		cnt2 = 0;

		for (int i = 0; i < n / 2 - 1; i++)
		{
			for (int j = i+1; j < n / 2; j++)
			{
				sum1 += value[answer[i]][answer[j]] + value[answer[j]][answer[i]];
			    sum2 += value[list[i]][list[j]] + value[list[j]][list[i]];
			}
		}

		int sub = abs(sum1 - sum2);
		if (minStat > sub || minStat == 40001) {
		     minStat = sub;
		}
		return;
	}

	for (int i = start; i < n; i++)
	{
		if (isVisited[i] == true) continue;
		isVisited[i] = true;

		dfs(depth + 1,i+1); //start+1이 아니라 i+1로 

		isVisited[i] = false;

	}
}



int main(int argc, char** argv)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> value[i][j];
		}
	}

	dfs(0,0);

	cout << minStat;


	return 0;
}