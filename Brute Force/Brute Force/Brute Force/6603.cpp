#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char argv) {
	

	while (true)
	{
		int n;
		vector<int> v;
		
		cin >> n; if (n == 0) break;
		
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}

		for (int i = 0; i < n; i++) {
			vector<int> v_2;
			for (int j = i,k = 0; k < 6; j++,k++) {
				v_2.push_back(v[j % n]);
				
			}

			sort(v_2.begin(), v_2.end());
			for (int j = 0; j < v_2.size(); j++) {
				cout << v_2[j] << ' ';
			}
			cout << '\n';

		}
	}


	return 0;
}