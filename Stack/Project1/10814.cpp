#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(const pair<pair<int,int>, string>& a, const pair<pair<int,int>, string>& b)
{
	if (a.first.first == b.first.first) {
		return a.first.second < b.first.second;
	}

	return a.first.first < b.first.first;
}

int main(int argc, char** argv) {
	
	int n;
	vector<pair<pair<int,int>, string>> v;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		string str;

		cin >> a >> str;
		v.push_back(make_pair(make_pair(a,i), str));
	}

	sort(v.begin(), v.end(), compare);
	
	for (int i = 0; i < n; i++) {
		cout << v[i].first.first << ' ' << v[i].second << '\n';
	}

	return 0;
}