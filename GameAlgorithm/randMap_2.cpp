#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include <cstring>
#include <algorithm>
#define SIZE 5
using namespace std;

//2. 룸 종류 열거형을 만든다.
enum RoomType
{
	ROOM_NORMAL,
	ROOM_KITCHEN,
	ROOM_BOSS
};

//1. 룸 클래스를 만든다.
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

//좌 우 하 상
int dx[4] = { -1 ,1,0,0 };
int dy[4] = { 0,0,1,-1 };


//3. 룸 클래스 배열 [5][5]를 만든다.  
Room roomList[SIZE][SIZE];
int lastDepth = 1;
int roomCnt, tempCnt;

//룸 그래프
vector<int> roomGrapth[SIZE * SIZE];

//시작 정점
int startX;
int startY;


void dfs(int x, int y, int depth)
{
	//이미 방이 다 만들어졌다면 더 로직을 진행할 필요가 없다.
	if (tempCnt == 0) return;

	//만들 수 있는 방 개수
	int curCnt = 0;
	bool isDir[4];
	memset(isDir, false, sizeof(isDir));

	//4방향에서 갈 수 있는 방향을 파악한 후, 그 중에 한 방향을 골라 이동한다.
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i]; int ty = y + dy[i];
		if (tx >= 0 && ty >= 0 && tx < SIZE && ty < SIZE && roomList[ty][tx].isCreated == 0) {
			curCnt++;
			isDir[i] = true;
		}
	}
	if (curCnt == 0) return; //더 나아갈 수 없다면 리턴
	int temp = (rand() % curCnt) + 1; //1~최대한 만들 수 있는 방개수 중 랜덤으로 택
	curCnt = temp;

	for (int i = 0; i < 4; i++) {

		if (curCnt == 0)return; //방 다 만들었다면 리턴
		if (tempCnt == 0) return;

		//어디방향으로 갈지 택
		int dir = rand() % 4;

		//한쪽 방향 쏠림 방지
		while (isDir[dir] != true) {
			dir = rand() % 4;

			//무한루프 이슈 방지용 임시 땜빵..추후 수정예정
			int sum = 0;
			for (int j = 0; j < 4; j++) {
				sum += isDir[j];
			}
			if (sum == 0)return;
		}
		//한번 택한 방향은 선택할 수 없게 처리
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

	//시작 방은 길이 1로 초기화
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

	//4. 카운트를 초기화 한다.
	srand((unsigned int)time(NULL));
	roomCnt = rand() % (20 - 10 + 1) + 10; //10~20의 난수
	tempCnt = roomCnt;


	//시작방 좌표 정하기
	startX = 0, startY = 0;
	
	//DFS로 그래프 생성
	roomList[startY][startX].isCreated = 1;
	dfs(startX, startY, 1);

	//BFS로 시작방 까지의 거리 구하기
	bfs(startX, startY, 1);
	
	

	//맵 출력
	for (int y = 0; y < SIZE; y++) {
		for (int x = 0; x < SIZE; x++) {
			int order = (x + 1) + (y * SIZE);
			cout << ' ' << roomList[y][x].isCreated << ' ';
		}
		cout << '\n';
	}

	cout << "보스방까지의 거리 : " << lastDepth;

	return 0;
}

