#include <iostream>

#include <vector>

#include <queue>

#define MAX 10001

using namespace std;

typedef struct node

{

	int row; //level	
	int col;

	int left;

	int right;

	int parent = -1;

}node;

vector<node> graph;

vector<int> rowFinNode[MAX];

bool isVisited[MAX];

int N, ans;

int colCnt = 1;

void bfs(int root)

{

	queue<int> q;

	q.push(root);

	graph[root].row = 1;

	rowFinNode[graph[root].row].push_back(1);

	while (!q.empty())

	{

		int now = q.front();

		q.pop();

		if (graph[now].left != -1)

		{
			int left = graph[now].left;

			graph[left].row = graph[now].row + 1;

			rowFinNode[graph[left].row].push_back(left);

			q.push(graph[now].left);

		}

		if (graph[now].right != -1)

		{
			int right = graph[now].right;

			graph[right].row = graph[now].row + 1;

			rowFinNode[graph[right].row].push_back(right);

			q.push(graph[now].right);

		}

	}

}

void inOrder(int root)

{



	if (graph[root].left != -1)

	{

		inOrder(graph[root].left);

	}

	graph[root].col = colCnt;

	colCnt++;

	if (graph[root].right != -1)

	{

		inOrder(graph[root].right);

	}

}

int main(int argc, char* argv[])

{

	cin >> N;

	node n{ -1,-1,-1,-1,-1 };

	for (int i = 0; i <= N; i++) {
		graph.push_back(n);
	}

	for (int i = 0; i < N; i++)

	{

		int now, left, right;

		cin >> now >> left >> right;

		graph[now].left = left;

		graph[now].right = right;

		if(left!=-1)graph[left].parent = now;

		if(right!=-1)graph[right].parent = now;

	}

	int root;

	for (int i = 1; i <= N; i++)

	{

		if (graph[i].parent == -1)

		{

			root = i;

			break;

		}

	}

	bfs(root);

	inOrder(root);

	//dfs(root);

	int ans = 1;

	int ansLev = 1;



	for (int i = 2; i <= N; i++) {

		if (!rowFinNode[i].empty()) {
			int temp = graph[rowFinNode[i].back()].col - graph[rowFinNode[i].front()].col+1;

			if (ans < temp) { ans = temp; ansLev = i; }
		}
	}



	cout << ansLev << ' ' << ans;



}