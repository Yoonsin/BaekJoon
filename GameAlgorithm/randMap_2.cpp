#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include <cstring>
#include <algorithm>
#define SIZE 5
using namespace std;

//2. �� ���� �������� �����.
enum RoomType
{
	ROOM_NORMAL,
	ROOM_KITCHEN,
	ROOM_BOSS
};

//1. �� Ŭ������ �����.
class Room
{
public:
	int roomNum;
	int isCreated;
	int roomType;

	void setRoomInfo(int num);

};

void Room::setRoomInfo(int order)
{
	{
		this->roomNum = order;
		this->isCreated = 0;
		this->roomType = ROOM_NORMAL;
	}
}

//�� �� �� ��
int dx[4] = { -1 ,1,0,0 };
int dy[4] = { 0,0,1,-1 };


//3. �� Ŭ���� �迭 [5][5]�� �����.  
Room roomList[SIZE][SIZE];
int lastDepth = 1;
int roomCnt, tempCnt;

//�� �׷���
vector<int> roomGrapth[SIZE * SIZE];

//���� ����
int startX;
int startY;


void dfs(int x, int y, int depth)
{
	//�̹� ���� �� ��������ٸ� �� ������ ������ �ʿ䰡 ����.
	if (tempCnt == 0) return;

	//���� �� �ִ� �� ����
	int curCnt = 0;
	bool isDir[4];
	memset(isDir, false, sizeof(isDir));

	//4���⿡�� �� �� �ִ� ������ �ľ��� ��, �� �߿� �� ������ ��� �̵��Ѵ�.
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i]; int ty = y + dy[i];
		if (tx >= 0 && ty >= 0 && tx < SIZE && ty < SIZE && roomList[ty][tx].isCreated == 0) {
			curCnt++;
			isDir[i] = true;
		}
	}
	if (curCnt == 0) return; //�� ���ư� �� ���ٸ� ����
	int temp = (rand() % curCnt) + 1; //1~�ִ��� ���� �� �ִ� �氳�� �� �������� ��
	curCnt = temp;

	for (int i = 0; i < 4; i++) {

		if (curCnt == 0)return; //�� �� ������ٸ� ����
		if (tempCnt == 0) return;

		//���������� ���� ��
		int dir = rand() % 4;

		//���� ���� �� ����
		while (isDir[dir] != true) {
			dir = rand() % 4;

			//���ѷ��� �̽� ������ �ӽ� ����..���� ��������
			int sum = 0;
			for (int j = 0; j < 4; j++) {
				sum += isDir[j];
			}
			if (sum == 0)return;
		}
		//�ѹ� ���� ������ ������ �� ���� ó��
		isDir[dir] = false;
		int tx = x + dx[dir];
		int ty = y + dy[dir];

		if (tx >= 0 && ty >= 0 && tx < SIZE && ty < SIZE && roomList[ty][tx].isCreated == 0) {

			roomList[ty][tx].isCreated = roomList[y][x].isCreated + 1;
			//int befNode = roomList[y][x].roomNum;
			//int curNode = roomList[ty][tx].roomNum;

			curCnt--;
			tempCnt--;
			dfs(tx, ty, roomList[ty][tx].isCreated);
		}
	}

}

void bfs(int x, int y, int depth) {
	int isVisited[SIZE][SIZE];
	memset(isVisited, 0, sizeof(isVisited));

	//���� ���� ���� 1�� �ʱ�ȭ
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	isVisited[y][x] = 1;
	roomList[y][x].isCreated = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i];
			int ty = y + dy[i];

			if (tx >= 0 && tx < SIZE && ty >= 0 && ty < SIZE && isVisited[ty][tx] == 0 && roomList[ty][tx].isCreated != 0) {
				isVisited[ty][tx] = isVisited[y][x] + 1;
				roomList[ty][tx].isCreated = isVisited[ty][tx];
				q.push(make_pair(tx, ty));
				
				lastDepth = max(lastDepth, roomList[ty][tx].isCreated);
			}

		}
		
	}

}

int main(int argc, char** argv)
{
	for (int y = 0; y < SIZE; y++) {
		for (int x = 0; x < SIZE; x++) {
			int order = (x + 1) + (y * SIZE);
			roomList[y][x].setRoomInfo(order);
		}
	}

	//4. ī��Ʈ�� �ʱ�ȭ �Ѵ�.
	srand((unsigned int)time(NULL));
	roomCnt = rand() % (20 - 10 + 1) + 10; //10~20�� ����
	tempCnt = roomCnt;


	//���۹� ��ǥ ���ϱ�
	startX = 0, startY = 0;
	
	//DFS�� �׷��� ����
	roomList[startY][startX].isCreated = 1;
	dfs(startX, startY, 1);

	//BFS�� ���۹� ������ �Ÿ� ���ϱ�
	bfs(startX, startY, 1);
	
	

	//�� ���
	for (int y = 0; y < SIZE; y++) {
		for (int x = 0; x < SIZE; x++) {
			int order = (x + 1) + (y * SIZE);
			cout << ' ' << roomList[y][x].isCreated << ' ';
		}
		cout << '\n';
	}

	cout << "����������� �Ÿ� : " << lastDepth;

	return 0;
}

