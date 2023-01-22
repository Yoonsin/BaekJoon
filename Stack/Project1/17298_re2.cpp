#include <iostream>
#include <stack>
using namespace std;

//Âü°í https://gamedoridori.tistory.com/76

int main(int argc, char** argv) {
	int arr[1000001];
	int t;
	cin >> t;
	stack<int> s;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		arr[i] = n;
		while (true)
		{
			if (s.empty()) {
				s.push(i);
				break;
			}
			else {
				int idx = s.top();

				if (n > arr[idx]) {
					arr[idx] = n;
					s.pop();
				}
				else {
					s.push(i);
					break;
				}
			}
		}
	}

		while (!s.empty())
		{
			int idx = s.top();
			arr[idx] = -1;
			s.pop();
		}

		for (int i = 0; i < t; i++) {
			cout << arr[i] << " ";
		}
	

}