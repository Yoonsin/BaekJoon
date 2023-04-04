#include <iostream>
#include <set>
#include <algorithm>
#include <stdlib.h>
#define MAX 20
using namespace std;

int value[MAX + 1][MAX + 1];
bool isVisited[MAX + 1];
int n;
int min_gap = 40000 + 1;

//참고 https://ongveloper.tistory.com/309

void dfs(int depth, int start)
{
	if (depth == n / 2)
	{
		set<int> s1; //스타트팀
		set<int> s2; //링크팀

		//value 계산용
		int temp1 = 0;
		int temp2 = 0;

		for (int i = 0; i < n; i++)
		{
			if (isVisited[i])
			{
				if (s2.find(i) != s2.end()) //이미 링크팀에 있는 멤버라면
				{
					s2.erase(s2.find(i));
					s1.insert(i); //링크팀에서 빼서 스타트 팀에 넣기

					//for(auto it = s1.begin(); it ) 시간 초과 줄이기 노력중...

				}
				else {
					s1.insert(i);
				}

				
				if (s2.empty()) //링크팀 한번만 멤버 채우면 두번 다시 할필요 없음(이거 안하면 시간초과 뜸!!!!!!)
				{
					for (int j = 0; j < n; j++)
					{
						if (s1.find(j) == s1.end()) //스타트팀에 없는 멤버라면
						{
							s2.insert(j); //링크팀에 넣기
						}
					}
				}

				
			}

			

			
			if (s1.size() == 1) //계산도 한번만 하면 충분함
			{
				for (auto it = s1.begin(); it != s1.end(); it++)
				{
					for (auto it2 = s1.begin(); it2 != it; it2++)
					{
						temp1 += value[*it][*it2] + value[*it2][*it];
					}
				}

			

			/*
			cout <<  "temp1: " << temp1 << " temp2: " << temp2 << '\n';
			cout << "set1 size : " << s1.size() << " set2 size : " << s2.size() << '\n';
			cout << '\n';
			*/

			if (s1.size() > 1 && s2.size() > 1) //팀 한명만 있으면 능력치가 0이어서 2명 이상이어야 함
			{
				min_gap = min(min_gap, abs(temp1 - temp2));
			}
			

		}



		return;
	}

	for (int i = start; i < n; i++)
	{
		if (isVisited[i]) continue;

		isVisited[i] = true;
		dfs(depth + 1, i + 1);
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

	dfs(0, 0);

	cout << min_gap;

	return 0;
	
}