#include <iostream>
#include <string>
using namespace std;

//참고 https://yjios.tistory.com/8
//이 채널에 고장난 버튼이 들어가지 않는지 확인
//이 채널에 가는 데 필요한 버튼 클릭 수와 최솟값을 비교
//한자리가 아닌 숫자 전체를 생각할것!!!!!!!!!!!!
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