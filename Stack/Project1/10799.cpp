//����. ���� Ǯ�̰� �����س��� ������� �ٸ� �� ��α� https://etyoungsu.tistory.com/36 �� �����ߴ�. ���� Ǯ����ҵ�.
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
			if (str[i - 1] == '(') { //������
				s.pop(); //�������� �ش��ϴ� '('�� ��������
				cnt += s.size();
			}
			else { //����� ��
				s.pop();
				cnt += 1;
			}
		}
	}

	cout << cnt;

	return 0;
}