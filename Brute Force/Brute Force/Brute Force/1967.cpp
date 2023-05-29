#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;

typedef struct node {

	int parent = -1;
	vector<int> child;
	int value = 0;
}node;


int N;
node NodeList[MAX];

int dfs(node root) {
	
	int value = 0;

	if (root.child.empty()) return root.value;


	for (int i = 0; i < root.child.size(); i++) {
		
		int temp = dfs(NodeList[root.child[i]]);

		if (value < temp)value = temp;

	}


	return value;


}


int main(int argc, char** argv) {

	cin >> N;
	
	for (int i = 0; i < N - 1; i++) {
		int now, child, value;

		cin >> now >> child >> value;

		NodeList[now].child.push_back(child);
		NodeList[child].parent = now;
		NodeList[child].value = value;
	}

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		node now = NodeList[i];
		vector<int> temp;

		if (now.child.size() == 0) continue; //말단노드면 해줄필요 없음

		for (int i = 0; i < now.child.size(); i++) {
			temp.push_back(dfs(NodeList[now.child[i]])); //각 서브트리의 길이파악
		}

		sort(temp.begin(), temp.end());
		
		if (now.child.size() >= 2) {
			if (ans < temp[0] + temp[1]) {
				ans = temp[0] + temp[1];
			}
		}
		else {
			if (ans < temp[0]) {
				ans = temp[0];
			}
		}
		
	}


	cout << ans;

	return 0;
}