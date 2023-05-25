#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<char> st; //문자 검사할 스택

	string str, bombStr;
	cin >> str;
	cin >> bombStr;
	int cnt = 0; //폭발 문자열 검사할 카운트
	int size = 0; //문자열 사이즈 검사해줄 변수


	while (str.size() != size)
	{
		size = str.size();
		for (int i = 0; i < str.size(); i++) {
			st.push(str[i]);
			if (str[i] == bombStr[cnt]) {
				cnt++;
				if (cnt == bombStr.size()) {
					//만약 스택에 폭발 문자열이 있다면
					for (int i = 0; i < cnt; i++) {
						//폭발 문자열은 빼기
						st.pop();
					}

					cnt = 0;
				}
			}
		}


		str.clear();
		for (int i = st.size() - 1; i >= 0; i--) {
			str.insert(0,1,st.top());
			st.pop();
		}

	}

	if (str.size() == 0) {
		cout << "FRULA";
	}
	else {
		cout << str;
	}

	
	return 0;
}