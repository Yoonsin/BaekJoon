#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char** argv) {
	int n, k,tmp;
	queue<int> q;

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	cout << '<';
	while (q.size() != 1) { //0이 아니라 1인 이유는 마지막 숫자는 ", "와 같이 출력하면 안되기 때문
		for (int i = 0; i < k - 1; i++) {
			tmp = q.front();
			q.push(tmp);
			q.pop();
		}
		cout << q.front() << ", ";
		q.pop();
	}

	tmp = q.front();
	q.pop();
	cout << tmp << '>';

	
	return 0;
}