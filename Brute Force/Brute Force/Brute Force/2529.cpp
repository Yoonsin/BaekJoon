#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#define MAX 10
using namespace std;

int answer[MAX];
char sign[MAX];
bool isVisited[MAX];
int N;
long long max_num = -1; long long min_num = 10000000000;
string max_str = "";
string min_str = "";

void dfs(int depth)
{
	
	if (depth == N + 1)
	{
		long long sum = 0;

		for (int i = N, j = 0; i >= 0; i--, j++)
		{
			sum += pow(answer[j], i);
		}

		max_num = max(max_num, sum);
		min_num = min(min_num, sum);

		
		if (max_num == sum)
		{
			string temp = "";
			for (int i = 0; i < depth; i++)
			{
				temp = temp.insert(i, 1, answer[i] + '0');
			}
			max_str = temp;
		}

		if (min_num == sum)
		{
			string temp = "";
			for (int i = 0; i < depth; i++)
			{
				temp = temp.insert(i, 1, answer[i] + '0');
			}
			min_str = temp;
		}

		return;
	}

	for (int i = 0; i < MAX; i++)
	{
		if (isVisited[i]) continue;
		if (depth > 0)
		{
			switch (sign[depth-1])
			{
			case '<':
				if (answer[depth - 1] >= i) continue;
				break;
			case '>':
				if (answer[depth - 1] <= i) continue;
				break;
			}
		}

		isVisited[i] = true;
		answer[depth] = i;
		dfs(depth + 1);
		isVisited[i] = false;
	
	}

}


int main(int argc, char** argv)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> sign[i];
	}

	dfs(0);
	cout << max_str << '\n';
	cout << min_str;

	return 0;
}