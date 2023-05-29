#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100000+1
using namespace std;

vector<int> v_2[MAX]; // �ε����� ����.  ���� ���� ���̿� �ִ� ��� ��ȣ��.

vector<int> v[MAX]; // �ε����� ��� ��ȣ. ���� �ε��� ��ȣ�� ���� ����Ǿ��ִ� ��� ��ȣ�� 

bool isVisited[MAX];

int N;  // ���� ����

int input[MAX]; //�Է����� �־��� BFS �湮 ����

void bfs()
{
	queue<pair<int, int>> q; //����ȣ, ����

	//�������� Ǫ��
	q.push(make_pair(1, 0));
	isVisited[1] = true;

	//������ ���� üũ���� ����
	int last_depth = 0;

	while (!q.empty())
	{
		int node = q.front().first;
		int depth = q.front().second;
		q.pop();

		v_2[depth].push_back(node);
		last_depth = depth;

		//���� ���� ����� ���� ���� Ž��
		for (int i = 0; i < v[node].size(); i++)
		{
			int next = v[node][i];
			if (!isVisited[next]) {
				q.push(make_pair(next, depth + 1));
				isVisited[next] = true;
			}
		}

	}

	int start = 0;
	int end = 0;

	for (int i = 0; i <= last_depth; i++)
	{
		//v_2[i]�� ����� �� ����.
		//������ ���۰� ���� �˰�. input ������ Ư�������� Ȯ������ �� �� ���� ���ٸ� Ʋ����
		end = start + v_2[i].size() -1 ;

		//input �迭�� v_2 �迭�� ���� �ľ����ִ� ����
		set<int> s;
		for (int j = 0; j < v_2[i].size(); j++)
		{
			int now = v_2[i][j];
			s.insert(now);
		}

		//ť���� ���� ������ ������ ���������Ǵ� ���������� �ľ����ִ� �迭
		vector<int> v_3; 

		for (int j = start; j <= end; j++)
		{
			//���� ������ ���� ���ٸ�
			if (s.find(input[j]) == s.end())
			{
				cout << 0;
				return;
			}
			else {
				//������ ���� �־
				//ť���� ���� ������ ������ �߸������� �װ͵� Ʋ����.
				if (i >= 1) {
					//���� ������ ����
					int pre_start = start - v_2[i-1].size();
					int pre_end = start - 1;

					for (int x = pre_start; x <= pre_end; x++)
					{
						int now = input[x];

						//���� ��尡 ���� ���� ���° ���� �̾��� �ִ��� ���� �ľ�. 
						if (find(v[now].begin(), v[now].end(), input[j]) != v[now].end()) {
							v_3.push_back(x);
						}
					}

				}
			}
		}

		/* Print
		cout << "depth " << i << '\n';
		for (int j = 0; j < v_3.size(); j++) {
			
			cout << v_3[j] << ' ';
		}
		cout << '\n';
		*/

		for (int j = 1; j < v_3.size(); j++)
		{
			//ť���� ���� ������ ������ ���������̳� ���� ������ Ʋ�� ��.
			if (v_3[j - 1] > v_3[j]) {
				cout << 0;
				return;
			}
		}

		start = end + 1;
	}

	//���� ���ο� ���� �ִ�==�ùٸ� ���̴�.
	cout << 1;
	

}

int main(int argc, char* argv[])
{
	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);

	}

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		input[i] = a;

	}

	if (input[0] != 1) {
		cout << 0;
		return 0;
	}

	bfs();


}

