#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 3000+1
using namespace std;

int N;
bool Cycle;
bool isVisited[MAX];
bool Check_Cycle_Station[MAX];
vector<int> Station[MAX];

void DFS(int Cur, int Start, int line) //���翪, ���ۿ�, ����� ��
{
	if (Cur == Start && line >= 2)
	{
		Cycle = true;
		return;
	}

	isVisited[Cur] = true;
	for (int i = 0; i < Station[Cur].size(); i++) //����Ǿ��ִ� ��翪...
	{
		int Next = Station[Cur][i]; //����� ��
		if (isVisited[Next] == false)
		{
			DFS(Next, Start, line + 1);
		}
		else {
			//���� ��忡 ����� ��尡 ���� ���̶��
			if (Next == Start && line >= 2) {
				DFS(Next, Start, line+1); //��ȯ���̹Ƿ� �湮���ֱ�
			}
		
		}

		if (Cycle == true) return; //�̹� ��ȯ�� �ִٰ� �Ǹ��� Ž������ �ʿ� ����
	}


}

int BFS(int a)
{
	memset(isVisited, false, sizeof(isVisited));
	queue<pair<int, int>> q;
	q.push(make_pair(a, 0));
	isVisited[a] = true;

	while (!q.empty())
	{
		int cur = q.front().first; //�湮 ��� �̸�
		int cnt = q.front().second; //��ȯ������ �Ÿ�
		q.pop();

		if (Check_Cycle_Station[cur] == true) return cnt; //��ȯ���̸� cnt ��ȯ

		for (int i = 0; i < Station[cur].size(); i++)
		{
			int next = Station[cur][i];
			if (isVisited[next] == false)
			{
				isVisited[next] = true;
				q.push(make_pair(next, cnt + 1));
			}
		}
	}



}



int main(int argc, char** argv)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		Station[a].push_back(b);
		Station[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		memset(isVisited, false, sizeof(isVisited));
		Cycle = false;

		int Start_Station = i;
		DFS(i, Start_Station, 0);

		if (Cycle == true)
		{
			Check_Cycle_Station[i] = true; //i�� ���� ��ȯ���� �ִ�.
		}
	}

	vector<int> Answer;
	for (int i = 1; i <= N; i++)
	{
		if (Check_Cycle_Station[i] == true)
		{
			Answer.push_back(0); //��ȯ���� �ִ� ���� ��ȯ���� �Ÿ��� 0
			continue;
		}

		Answer.push_back(BFS(i));
	}

	for (int i = 0; i < Answer.size(); i++)
	{
		cout << Answer[i] << " ";
	}
	cout << '\n';


	return 0;
}