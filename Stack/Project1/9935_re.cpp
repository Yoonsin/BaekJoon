#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	string bombStr;
	string temp = "";

	cin >> str >> bombStr;
	int str_len = str.size();
	int bombStr_len = bombStr.size();

	for (int i = 0; i < str.size(); i++) {
		temp += str[i];
		if (temp.size() >= bombStr.size()) {
			bool flag = true;
			for (int j = 0; j < bombStr.size(); j++) {
				if (temp[temp.size() - bombStr.size() + j] != bombStr[j]) {
					flag = false;
					break;
				}
			}

			if (flag)
				temp.erase(temp.end() - bombStr.size(), temp.end());
		}
	}

	if (temp.empty()) {
		cout << "FRULA" << '\n';
	}
	else {
		cout << temp << '\n';
	}


}