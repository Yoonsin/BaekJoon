#include <iostream>
#include <vector>
#define MAX 20001
using namespace std;

int v, e; //v: 정점개수 e: 간선개수
bool isVisited[MAX];
int arr[MAX];
vector<int> ve[MAX];
bool ans;
//depth은 0부터 시작
void dfs(int depth, int start){

	if (depth = v - 1) {
		return;
	}

	for (int i = start; i <= v; i++)
	{
		if (depth == 0 && i != 1) return; //1에 대한 조합만 찾으면 됨
		if (isVisited[i]) continue;
		
		//현재 방문한 노드들이 인접하지 않은지 확인
		bool flag = false;
		if (depth > 0) {
			for (int j = 0; j < depth; j++)
			{
				if (flag) break;
				//방문상태인 노드들(arr) 전부 순회
				//지금 방문한 노드(i)와 서로 관계가 있는지 확인
				for (int k = 0; k < ve[arr[j]].size(); k++)
				{
					if (ve[i][k] == arr[depth] || ve[arr[depth]][k] == i) {
						flag = true;
					}
				}
					
			}
		}
		if (flag) return;

		arr[depth] = i;
		isVisited[i] = true;
		
		//나머지 노드들이 인접한지 않은지 확인
		flag = false;
		vector<int> ve_2;
		for (int j = 1; j <= v; j++)
		{
			if (isVisited[j] == false)
			{
				ve_2.push_back(j);
			}
		}

		for (int j = 0; j < ve_2.size()-1; j++)
		{
			for (int k = j + 1; k < ve_2.size(); k++)
			{
				for (int x = 0; x < ve[ve_2[j]].size(); x++)
				{
					if (ve[ve_2[j]][x] == ve_2[i])
					{
						flag = true;
					}
				}

				for (int x = 0; x < ve[ve_2[i]].size(); x++)
				{
					if (ve[ve_2[i]][x] == ve_2[j])
					{
						flag = true;
					}
				}
			}
		}

		if (flag) {
			ans = true;
		}

		
		dfs(depth + 1, i + 1);
		isVisited[i] = false;
		
	}
}

int main(int argc, char** argv)
{
	int t;
	
	cin >> t;
	while (t--)
	{
		cin >> v >> e;
		
		for (int i = 0; i < e; i++)
		{
			int a, b;
			cin >> a >> b;
			ve[a].push_back(b);
			ve[b].push_back(a);
		}

		dfs(0, 1);

		if (ans)
		{
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
	

	return 0;
}