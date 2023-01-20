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
	while (q.size() != 1) { //0�� �ƴ϶� 1�� ������ ������ ���ڴ� ", "�� ���� ����ϸ� �ȵǱ� ����
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