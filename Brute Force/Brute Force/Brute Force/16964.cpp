#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 100001
using namespace std;

vector<int> node[MAX];
int nodeDepth[MAX]; //인덱스는 노드 번호, 값은 깊이
bool isVisited[MAX];
int lastDepth = -1; //말단 노드 판단을 위한 변수

int input[MAX];
int N;



void dfs(int depth,int now)
{
	lastDepth = max(lastDepth, depth);

	for (int i = 0; i < node[now].size(); i++)
	{
		int next = node[now][i];
		if (isVisited[next]) continue;

		isVisited[next] = true;
		nodeDepth[next] = depth + 1;
		dfs(depth + 1, next);
	}
}


int main(int argc, char** argv)
{
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		input[i] = a;
	}

	if (input[0] != 1) { cout << 0; }

	//시작정점은 항상 1
	isVisited[1] = true;
	nodeDepth[1] = 0;
	dfs(0,1);


	memset(isVisited, 0, sizeof(isVisited));
	isVisited[1] = true;

	for (int i = 1; i < N; i++)
	{
		int now = input[i]; //현재 방문할 노드
		int pre = input[i - 1]; //이전(i-1) 노드

		int nowDepth = nodeDepth[now]; //현재 방문할 노드의 깊이 (임의로 '현재노드'라고 통칭)
		int preDepth = nodeDepth[pre]; //이전 노드의 깊이

		int nowParent = 0; //현재 방문할 노드의 부모노드

		//현재 노드랑 연결되있는 노드가 만약 현재 노드보다 깊이가 1층 높다 ==> 현재노드의 부모노드
		for (int j = 0; j < node[now].size(); j++) {
			int temp = node[now][j];
			if (nodeDepth[temp] == nowDepth - 1) {
				int nowParent = temp;
				break;
			}
		}

		if (nowDepth > preDepth) {

			if (nowParent == pre) {
				isVisited[now] = true;
			}
			else {
				cout << 0;
				return 0;
			}

		}
		else {
			//이전 노드가 말단 노드였고, 현재 노드가 방문했던 노드가 아니라면
			if ((preDepth == lastDepth) && (!isVisited[now])) {
				
				int preAncestor = 0;
				int preParent = 0;
				int AncestorDepth = 0;
				for (int j = 0; j < node[pre].size(); j++)
				{
					int temp = node[pre][j];
					if (nodeDepth[temp] == preDepth - 1) {
						preAncestor = temp;
						preParent = temp;
						AncestorDepth = nodeDepth[preAncestor];
						break;
					}
				}

				while (1) {
					if (nodeDepth[preAncestor] == nodeDepth[nowParent]) {
						
						for (int j = 0; j < node[preParent].size(); j++)
						{
							int temp = node[preParent][j];
							if (nodeDepth[temp] == nodeDepth[preParent] + 1)
							{
								if (!isVisited[temp]) {
									cout << 0;
									return 0;
								}
							}
						}
						isVisited[now] = true;
						break;
					}

					for (int j = 0; j < node[preAncestor].size(); j++)
					{
						int temp = node[preAncestor][j];
						if (nodeDepth[temp] == AncestorDepth - 1) {
							preAncestor = temp;
							AncestorDepth = nodeDepth[preAncestor];
							break;
						}
					}
				}
			}
			else {
				//nonpass
				cout << 0;
				return 0;
			}
		}
	}

	cout << 1;



	return 0;
}