//스택. 문제 풀이가 생각해내기 어려워서 다른 분 블로그 https://etyoungsu.tistory.com/36 를 참고했다. 많이 풀어야할듯.
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(int argc, char** argv) {
	string str;
	int cnt = 0;

	cin >> str;
	stack<int> s;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') 
			s.push(str[i]);
		else {
			if (str[i - 1] == '(') { //레이저
				s.pop(); //레이저에 해당하는 '('는 빠져야함
				cnt += s.size();
			}
			else { //막대기 끝
				s.pop();
				cnt += 1;
			}
		}
	}

	cout << cnt;

	return 0;
}