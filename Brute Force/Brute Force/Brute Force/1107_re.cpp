#include <iostream>
#include <string>
using namespace std;

//���� https://yjios.tistory.com/8
//�� ä�ο� ���峭 ��ư�� ���� �ʴ��� Ȯ��
//�� ä�ο� ���� �� �ʿ��� ��ư Ŭ�� ���� �ּڰ��� ��
//���ڸ��� �ƴ� ���� ��ü�� �����Ұ�!!!!!!!!!!!!
bool btn[10];
bool check(int num) {
	string n = to_string(num);
	for (int i = 0; i < n.size(); i++) {
		if (btn[n[i]-'0'])
			return false;
	}
	return true;
}


int main(int argc, char** argv) {

	
    int n,btnNum;
	string channel;

	//memset(btn, false, sizeof(btn));
	cin >> n;
	cin >> btnNum;
	for (int i = 0; i < btnNum; i++)
	{
		int b;
		cin >> b;
		btn[b] = true;
	}

	channel = to_string(n);

	int minNum = abs(n - 100);
	for (int i = 0; i < 1000000; i++) {
		int minNumSub = abs(n - 100);
		if (check(i)) {
			minNumSub = abs(n - i) + to_string(i).size();
			minNum = min(minNum, minNumSub);
		}

	}

	cout << minNum;

	return 0;
}