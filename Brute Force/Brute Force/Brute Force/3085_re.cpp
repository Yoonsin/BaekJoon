#include <iostream>
#define MAX 50
using namespace std;

int maxNum = 0;
char board[MAX][MAX];

void changeRow(char board[MAX][MAX],int size) {
	for (int i = 0; i < size; i++) {
		int n = 1;
		for (int j = 1; j < size; j++) {
			if (board[i][j - 1] == board[i][j]) {
				n++;
			}
			else {
				maxNum = max(maxNum, n);
				n = 1;
			}
		}
		maxNum = max(maxNum, n);
	}
}

void changeColumn(char board[MAX][MAX],int size) {
	for (int i = 0; i < size; i++) {
		int n = 1;
		for (int j = 1; j < size; j++) {
			if (board[j - 1][i] == board[j][i]) {
				n++;
			}
			else {
				maxNum = max(maxNum, n);
				n = 1;
			}
		}
		maxNum = max(maxNum, n);
		
	}
}


int main(int argc, char** argv) 
{
	int size;
	cin >> size;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			swap(board[i][j], board[i][j + 1]);//���� �ٲٱ�
			changeColumn(board,size);//���ΰ���üũ
			changeRow(board,size);//���ΰ���üũ
			swap(board[i][j], board[i][j + 1]);//���ƿ���

			swap(board[j][i], board[j + 1][i]);//���ιٲٱ�
			changeColumn(board,size);//���ΰ���üũ
			changeRow(board,size);//���ΰ���üũ
			swap(board[j][i], board[j + 1][i]);//���ƿ���
		}
	}

	cout << maxNum;

	return 0;
}