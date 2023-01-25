#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	string str;
	char cr;
	getline(cin, str, '\n');


	for (int i = 0; i < str.size(); i++) {
		cr = str[i];
		if (cr >= 'a' && cr <= 'm') {
			cr +=  13;
		}
		else if (cr >= 'n' && cr <= 'z') {
			cr -= 13;
		}
		else if (cr >= 'A' && cr <= 'M') {
			cr += 13;
		}
		else if (cr >= 'N' && cr <= 'Z') {
			cr -= 13;
		}
		cout << cr;
	}

	return 0;
}