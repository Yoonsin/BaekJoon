//시간 초과뜸ㅋㅋ O(n^2) 이라서..
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char** argv)
{
	int t; // test case
	int n;
	int nge;
	vector<int> v;
	
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		v.push_back(n);
	}
	
	for (int i = 0; i < v.size(); i++) {
		queue<int> q;
		
		for (int j = i + 1; j < v.size(); j++) {
			q.push(v[j]);
		}

		nge = -1;

		while (q.size())
		{
			if (v[i] < q.front()) {
				nge = q.front();
				break;
			}
			else {
				q.pop(); //next to element
			}
		}

		cout << nge << " ";
		
	}


	return 0;
}