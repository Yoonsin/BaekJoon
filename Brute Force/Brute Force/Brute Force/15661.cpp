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

//���� https://ongveloper.tistory.com/309

void dfs(int depth, int start)
{
	if (depth == n / 2)
	{
		set<int> s1; //��ŸƮ��
		set<int> s2; //��ũ��

		//value ����
		int temp1 = 0;
		int temp2 = 0;

		for (int i = 0; i < n; i++)
		{
			if (isVisited[i])
			{
				if (s2.find(i) != s2.end()) //�̹� ��ũ���� �ִ� ������
				{
					s2.erase(s2.find(i));
					s1.insert(i); //��ũ������ ���� ��ŸƮ ���� �ֱ�

					//for(auto it = s1.begin(); it ) �ð� �ʰ� ���̱� �����...

				}
				else {
					s1.insert(i);
				}

				
				if (s2.empty()) //��ũ�� �ѹ��� ��� ä��� �ι� �ٽ� ���ʿ� ����(�̰� ���ϸ� �ð��ʰ� ��!!!!!!)
				{
					for (int j = 0; j < n; j++)
					{
						if (s1.find(j) == s1.end()) //��ŸƮ���� ���� ������
						{
							s2.insert(j); //��ũ���� �ֱ�
						}
					}
				}

				
			}

			

			
			if (s1.size() == 1) //��굵 �ѹ��� �ϸ� �����
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

			if (s1.size() > 1 && s2.size() > 1) //�� �Ѹ� ������ �ɷ�ġ�� 0�̾ 2�� �̻��̾�� ��
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