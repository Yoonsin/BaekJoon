#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<char> st; //���� �˻��� ����

	string str, bombStr;
	cin >> str;
	cin >> bombStr;
	int cnt = 0; //���� ���ڿ� �˻��� ī��Ʈ
	int size = 0; //���ڿ� ������ �˻����� ����


	while (str.size() != size)
	{
		size = str.size();
		for (int i = 0; i < str.size(); i++) {
			st.push(str[i]);
			if (str[i] == bombStr[cnt]) {
				cnt++;
				if (cnt == bombStr.size()) {
					//���� ���ÿ� ���� ���ڿ��� �ִٸ�
					for (int i = 0; i < cnt; i++) {
						//���� ���ڿ��� ����
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