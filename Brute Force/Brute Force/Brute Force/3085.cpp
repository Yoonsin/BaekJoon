//https://www.acmicpc.net/problem/3085 참고
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
			swap(arr[i][j], arr[i][j + 1]); //가로 2칸 바꾸기
			columnCheck(arr,size); //갯수 세기
			rowCheck(arr, size); //갯수 세기
			swap(arr[i][j], arr[i][j + 1]); //다시 돌아오기
			
			swap(arr[j][i], arr[j + 1][i]); //세로 2칸 바꾸기
			columnCheck(arr, size); //갯수 세기
			rowCheck(arr, size); //갯수 세기
			swap(arr[j][i], arr[j + 1][i]); //다시 돌아오기

		}
	}

	cout << maxCnt;
	return 0;


}