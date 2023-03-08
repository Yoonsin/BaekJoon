#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//https://www.acmicpc.net/problem/1107 참고
int main(int argc, char** argv) 
{
	string channel;

	bool brokenBtn[10];
	int brokenBtnNum;
	memset(brokenBtn, 0, sizeof(brokenBtn));

	cin >> channel;
	cin >> brokenBtnNum;

	for (int i = 0; i < brokenBtnNum; i++) {
		int n;
		cin >> n;
		brokenBtn[n] = true;
	}

	/*
	bool notBrokenflag = true;
	for (int i = channel.size()-1; i>=0; i--) {
		int n = channel[i]-'0';
		for (int j = 0; j < 10; j++) {
			if (n == j && brokenBtn[j] == true) {
				notBrokenflag = false;
				break;
			}
				
		}
	}
	if (notBrokenflag == true) {
		cout << 0;
		return 0;
	}*/

	//각각의 자릿수 기준으로 체크하면 안됨 
	//작은 채널 -> 목표 채널 까지는 되지만 큰 채널 -> 목표 채널 까지는 안되기 때문
	//507 -> 600 600 -> 599 
	int answer = 0;
	for (int i = 0,idx=channel.size()-1; i < channel.size(); i++,idx--) {
		int gap = 10;
		int subAnswer = 0;
		for (int j = 0; j < 20; j++) {
			if (brokenBtn[j%10] == true)
				continue;

			if (abs((channel[idx]-'0') - j) < gap) {
				gap = abs((channel[idx] - '0') - j);
				subAnswer = j * pow(10, i);
			}
		}
		answer += subAnswer;
	}

	int btnPushNumber = abs(stoi(channel) - answer) + channel.size();
	if (abs(stoi(channel) - 100) < btnPushNumber) {
		btnPushNumber = abs(stoi(channel) - 100);
	}
	cout << btnPushNumber;
	



	return 0;
}