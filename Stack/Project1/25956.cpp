#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	vector<pair<int, int>> v; //first : 레벨 / second : answer에서의 index
	vector<int> answer; //하위 레벨

	int n;
	cin >> n;

	for (int idx = 0; idx < n; idx++) {
		int level;
		cin >> level;

		v.push_back(make_pair(level, idx));
		answer.push_back(0); //처음 값은 0

		if (v.size() < 2)continue;
		if (v[v.size()-1].first - v[v.size()-2].first >= 2 && v[v.size() - 1].first>v[v.size() - 2].first) {
			cout << -1;
			exit(1);
		}
		auto now = v[v.size() - 1];
		int cnt = v.size()-2; 
		//idx가 0부터 시작되기 때문에 -1, top-1 원소부터 접근해야해서 -1

		while (cnt >= 0) {
			auto temp = v[cnt];

			//temp 기준 now가 하위레벨 이었으면 +1
			if (now.first > temp.first) {
				answer[temp.second]++;
			}//temp 기준 now가 새 문단이면
			else if (now.first < temp.first) {
				int cnt_2 = 0;
				while (now.first <= v[cnt_2].first) {
					cnt_2++;
				}
				v.erase(v.begin() + cnt - cnt_2 + 1, v.begin() + cnt);
				cnt = cnt - cnt_2;
				continue;
			}
			cnt--;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << answer[i] << '\n';
	}



	return 0;
}