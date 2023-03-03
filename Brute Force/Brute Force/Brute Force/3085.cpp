//https://www.acmicpc.net/problem/3085 ����
#include <iostream>
#define MAX 50
using namespace std;

int maxCnt = 0;
char arr[MAX][MAX];
void columnCheck(char arr[][MAX], int size){	
	for (int i = 0; i < size; i++) {
		int cnt = 1;
		for (int j = 0; j < size; j++) {
			if (arr[i][j] == arr[i][j + 1])
				cnt++;
			else {
				if (cnt > maxCnt)
				{
					maxCnt = cnt;
				}
				cnt = 1;
			}
		}
	}
}

void rowCheck(char arr[][MAX], int size) {
	for (int i = 0; i < size; i++) {
		int cnt = 1;
		for (int j = 0; j < size; j++) {
			if (arr[j][i] == arr[j][i])
				cnt++;
			else {
				if (cnt > maxCnt)
				{
					maxCnt = cnt;
				}
				cnt = 1;
			}
		}
	}
}

int main(int argc, char** argv) 
{
	int size;
	cin >> size;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> arr[i][j];
		}
	}

	int cnt = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size-1; j++)
		{
			swap(arr[i][j], arr[i][j + 1]); //���� 2ĭ �ٲٱ�
			columnCheck(arr,size); //���� ����
			rowCheck(arr, size); //���� ����
			swap(arr[i][j], arr[i][j + 1]); //�ٽ� ���ƿ���
			
			swap(arr[j][i], arr[j + 1][i]); //���� 2ĭ �ٲٱ�
			columnCheck(arr, size); //���� ����
			rowCheck(arr, size); //���� ����
			swap(arr[j][i], arr[j + 1][i]); //�ٽ� ���ƿ���

		}
	}

	cout << maxCnt;
	return 0;


}