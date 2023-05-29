#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#define ROW 6 //Ʈ�� ����
#define COL 30 //Ʈ�� ����
using namespace std;

//Ʈ�� ��
int arr[ROW][COL];

//�� īƮ ��
int dx[2] = { 0,1 };
int dy[3] = { 0,1,-1 };
int cartX, cartY;
int dirX, dirY;

//�� īƮ ��
int emeDx[2] = { 0,1 };
int emeDy[3] = { 0,1,-1 };
int emeX, emeY;
int emeDirX, emeDirY;

//������ ��
int itemX = (COL - 1) / 2;
int itemY = (ROW - 1) / 2;


int main(int argc, char* argv[])
{
	//���� �õ尪 ����
	srand((unsigned int)time(NULL));

	//�� īƮ ��ġ �ʱ�ȭ
	cartX = 0;
	cartY = 0;
	//�� īƮ ��ġ �ʱ�ȭ
	emeX = 0;
	emeY = ROW - 1;


	while (1)
	{
		//īƮ ���
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {

				if (cartX == j && cartY == i)
				{
					cout << "��";
				}
				else if (emeX == j && emeY == i)
				{
					cout << "��";
				}
				else if (itemX == j && itemY == i) {

					cout << "��";
				}
				else {
					cout << "��";
				}
			}
			cout << '\n';
		}

		//�� īƮ ��ġ ����
		dirX = rand() % 2;
		dirY = rand() % 3;
		//cartX+=dx[dirX]; 
		//�ϴ� ������ �ǰ�
		cartX += 1;

		//Ʈ�� ����°� ����
		int temp = cartY + dy[dirY];
		while (temp < 0 || temp >= ROW)
		{
			dirY = rand() % 3;
			temp = cartY + dy[dirY];
		}
		cartY = temp;
		cartX %= COL;

		//�� īƮ ��ġ ����
		emeDirX = rand() % 2;
		emeDirY = rand() % 3;
		//cartX+=dx[dirX]; 
		//�ϴ� ������ �ǰ�
		emeX += 1;

		//Ʈ�� ����°� ����
		int temp_2 = emeY + emeDy[emeDirY];
		while (temp_2 < 0 || temp_2 >= ROW)
		{
			emeDirY = rand() % 3;
			temp_2 = emeY + emeDy[emeDirY];
		}
		emeY = temp_2;
		emeX %= COL;


		//0.2�� ���� ������Ʈ
		Sleep(200);
		system("cls");

	}
}

