#include <iostream>
#include <cstring>
#include <vector>
#define SIZE 100
#define MAX 1e9 //e는 10의 제곱. 10억
using namespace std;

int isEval[4]; // + - * /
int numEval[4];
vector<char> eval;
char evalArr[SIZE];

int arr[SIZE];
bool isVisited[SIZE];
int N;

int minVal = MAX + 1;
int maxVal = (-MAX) + 1;

void dfs(int depth) {
	if (depth == N - 1) {
		int sum = arr[0];
		//cout << arr[0];
		for (int i = 1; i < N; i++) {
			switch (evalArr[i-1]) {
			case '+':
				sum += arr[i];
				break;
			case '-':
				sum -= arr[i];
				break;
			case '*':
				sum *= arr[i];
				break;
			case '/':
				sum /= arr[i];
				break;
			}
			cout << evalArr[i - 1];
			cout << arr[i];
		}
		//cout << '\n';
		//cout << sum;
		if (sum > maxVal) { maxVal = sum; }
		if (sum < minVal) {minVal = sum;}
	}

	memset(isEval, 0, sizeof(isEval));

	for (int i = 0; i < eval.size(); i++) {
		int now;
		switch (eval[i]) {
		case '+':
			now = 0;
			break;
		case '-':
			now = 1;
			break;
		case '*':
			now = 2;
			break;
		case '/':
			now = 3;
			break;
		}

		if (!isVisited[i]) {
			isVisited[i] = true;
			if (!isEval[now]){
				isEval[now] = true;
				evalArr[depth] = eval[i];
				dfs(depth + 1);
				isVisited[i] = false;
			}
		}


	}


}


int main(int argc, char** argv) {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> numEval[i];
		for (int j = 0; j < numEval[i]; j++) {
			if (i == 0) {
				eval.push_back('+');
			}
			else if (i == 1) {
				eval.push_back('-');
			}
			else if (i == 2) {
				eval.push_back('*');
			}
			else if (i == 3) {
				eval.push_back('/');
			}
		}
		
	}

	//N=2 연산자 1개
	//depth = n-1개 탐색

	dfs(0);

	cout << maxVal << '\n';
	cout << minVal << '\n';

}