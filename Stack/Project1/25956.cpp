#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	vector<pair<int, int>> v; //first : ���� / second : answer������ index
	vector<int> answer; //���� ����

	int n;
	cin >> n;

	for (int idx = 0; idx < n; idx++) {
		int level;
		cin >> level;

		v.push_back(make_pair(level, idx));
		answer.push_back(0); //ó�� ���� 0

		if (v.size() < 2)continue;
		if (v[v.size()-1].first - v[v.size()-2].first >= 2 && v[v.size() - 1].first>v[v.size() - 2].first) {
			cout << -1;
			exit(1);
		}
		auto now = v[v.size() - 1];
		int cnt = v.size()-2; 
		//idx�� 0���� ���۵Ǳ� ������ -1, top-1 ���Һ��� �����ؾ��ؼ� -1

		while (cnt >= 0) {
			auto temp = v[cnt];

			//temp ���� now�� �������� �̾����� +1
			if (now.first > temp.first) {
				answer[temp.second]++;
			}//temp ���� now�� �� �����̸�
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