#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 20

//https://myunji.tistory.com/340 Âü°í
using namespace std;

int value[MAX][MAX];
int N;

int calcPower(vector<int> v) {
	int result = 0;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			result += value[v[i]][v[j]];
		}
	}

	return result;
}

int splitTeam(int num) {
	vector<int> start, link;

	for (int i = 0; i < N; i++) {
		if ((num & (1 << i)) == 0) {
			link.push_back(i);
		}
		else {
			start.push_back(i);
		}
	}
	return abs(calcPower(link) - calcPower(start));
}

int main(int argc, char** argv)
{
	int min_gap = -1;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> value[i][j];
		}
	}


	//0001 - 1 : 1-1 = 0 : 0000
	//0011 - 1 : 3-1 = 2 : 0010
	//0111 - 1 : 7-1 = 6 : 0110
	//1111 - 1 : 15-1 = 14 : 1110


	for (int i = 1; i < ((1 << N) - 1); i++)
	{
		if (min_gap == -1)
			min_gap = splitTeam(i);

		min_gap = min(min_gap, splitTeam(i));
	}
	cout << min_gap;
}