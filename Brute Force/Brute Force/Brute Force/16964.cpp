#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 100001
using namespace std;

vector<int> node[MAX];
int nodeDepth[MAX]; //�ε����� ��� ��ȣ, ���� ����
bool isVisited[MAX];
int lastDepth = -1; //���� ��� �Ǵ��� ���� ����

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

	//���������� �׻� 1
	isVisited[1] = true;
	nodeDepth[1] = 0;
	dfs(0,1);


	memset(isVisited, 0, sizeof(isVisited));
	isVisited[1] = true;

	for (int i = 1; i < N; i++)
	{
		int now = input[i]; //���� �湮�� ���
		int pre = input[i - 1]; //����(i-1) ���

		int nowDepth = nodeDepth[now]; //���� �湮�� ����� ���� (���Ƿ� '������'��� ��Ī)
		int preDepth = nodeDepth[pre]; //���� ����� ����

		int nowParent = 0; //���� �湮�� ����� �θ���

		//���� ���� ������ִ� ��尡 ���� ���� ��庸�� ���̰� 1�� ���� ==> �������� �θ���
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
			//���� ��尡 ���� ��忴��, ���� ��尡 �湮�ߴ� ��尡 �ƴ϶��
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