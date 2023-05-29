#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#define ROW 6 //트랙 세로
#define COL 30 //트랙 가로
using namespace std;

//트랙 □
int arr[ROW][COL];

//내 카트 ■
int dx[2] = { 0,1 };
int dy[3] = { 0,1,-1 };
int cartX, cartY;
int dirX, dirY;

//적 카트 ●
int emeDx[2] = { 0,1 };
int emeDy[3] = { 0,1,-1 };
int emeX, emeY;
int emeDirX, emeDirY;

//아이템 ☆
int itemX = (COL - 1) / 2;
int itemY = (ROW - 1) / 2;


int main(int argc, char* argv[])
{
	//랜덤 시드값 설정
	srand((unsigned int)time(NULL));

	//내 카트 위치 초기화
	cartX = 0;
	cartY = 0;
	//적 카트 위치 초기화
	emeX = 0;
	emeY = ROW - 1;


	while (1)
	{
		//카트 출력
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {

				if (cartX == j && cartY == i)
				{
					cout << "■";
				}
				else if (emeX == j && emeY == i)
				{
					cout << "●";
				}
				else if (itemX == j && itemY == i) {

					cout << "☆";
				}
				else {
					cout << "□";
				}
			}
			cout << '\n';
		}

		//내 카트 위치 변경
		dirX = rand() % 2;
		dirY = rand() % 3;
		//cartX+=dx[dirX]; 
		//일단 직진만 되게
		cartX += 1;

		//트랙 벗어나는거 방지
		int temp = cartY + dy[dirY];
		while (temp < 0 || temp >= ROW)
		{
			dirY = rand() % 3;
			temp = cartY + dy[dirY];
		}
		cartY = temp;
		cartX %= COL;

		//적 카트 위치 변경
		emeDirX = rand() % 2;
		emeDirY = rand() % 3;
		//cartX+=dx[dirX]; 
		//일단 직진만 되게
		emeX += 1;

		//트랙 벗어나는거 방지
		int temp_2 = emeY + emeDy[emeDirY];
		while (temp_2 < 0 || temp_2 >= ROW)
		{
			emeDirY = rand() % 3;
			temp_2 = emeY + emeDy[emeDirY];
		}
		emeY = temp_2;
		emeX %= COL;


		//0.2초 마다 업데이트
		Sleep(200);
		system("cls");

	}
}

