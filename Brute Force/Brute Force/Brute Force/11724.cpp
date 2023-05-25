#include <iostream>
#define MAX 1001
using namespace std;

int map[MAX][MAX];
bool isVisited[MAX];
int sum;
int n, m;
void dfs(int n,int depth)
{
	for (int i = 1; i <= n; i++)
	{	
		if (map[n][i] == 1 && isVisited[i] == false)
		{
			if (depth == 0) { 
				sum++; 
			}

			isVisited[i] = true;
			cout << 'i ';
			dfs(i, depth + 1);
		}
	}
}


int main(int argc, char** argv)
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;

		map[u][v] = 1;
	}

	isVisited[1] = true;
	dfs(1,0);

	cout << sum;
	return 0;
}