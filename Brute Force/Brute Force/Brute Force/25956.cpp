#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 1000001
using namespace std;

int level_buf[MAX];
int level_input[MAX];
queue<int> level[MAX];
int main(int argc, char** argv)
{
	int n;
	cin >> n;

	int pre_input;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		level_input[i] = input;

		if (i == 0)
		{
			if (input != 1)
			{
				cout << -1;
				exit(1);
			}
			pre_input = input;
		}
		else {
			if (input - 1 <= pre_input) {

				level_buf[input - 1]++;
				if (input <= pre_input) {
					for (int j = input; j <= pre_input; j++) {
						level[j].push(level_buf[j]);
					}
					memset(level_buf + input, 0, sizeof(int) * (pre_input - input + 1));
				}
				pre_input = input;
			}
			else {
				cout << -1;
				exit(1);
			}
		}
	}

	cout << '\n';
	for (int i = 0; i < n; i++) {
		if (!level[level_input[i]].empty()) {
			cout << level[level_input[i]].front() << '\n';
			level[level_input[i]].pop();
		}
	}



}

