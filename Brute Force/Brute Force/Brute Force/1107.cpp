#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//https://www.acmicpc.net/problem/1107 Âü°í
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

	int answer = 0;
	for (int i = 0,idx=channel.size()-1; i < channel.size(); i++,idx--) {
		int gap = 10;
		int subAnswer = 0;
		for (int j = 0; j < 10; j++) {
			if (brokenBtn[j] == true)
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