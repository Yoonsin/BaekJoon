#include <iostream>
#define MAX 20
using namespace std;

int sum_num; //부분수열의 개수
int s, n;
bool isVisited[MAX];
int arr[MAX];
int sum;
void dfs(int depth,int start)
{
	if (depth == n)
	{
		if (sum == s)
			sum_num++;

		return;
	}

	if (sum == s && depth > 0)
	{

		sum_num++;
	}

	for (int i = start; i < n; i++)
	{
		if (isVisited[i])continue;
		isVisited[i] = true;
		sum += arr[i];
		
		dfs(depth + 1,i+1);

		isVisited[i] = false;
		sum -= arr[i];
	}

}


int main(int argc, char** argv)
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	dfs(0, 0);
	

	cout << sum_num;

	return 0;
}