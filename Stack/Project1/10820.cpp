#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) 
{
	//int t = 0;
	string str;

	//cin >> t;
	//cin.ignore();
	while(getline(cin, str)) //EOF(컨트롤 z) 가 올때까지 계속 읽음
	{
		int num = 0;
		int low = 0, high = 0;
		int empty = 0;

	
		for (int j = 0; j < str.size(); j++) {
			if (str[j] >= 65 && str[j] <= 90) {
				high++;
			}
			else if (str[j] >= 97 && str[j] <= 122) {
				low++;
			}
			else if (str[j] >= 47 && str[j] <= 57) {
				num++;
			}
			else if (str[j] == 32) {
				empty++;
			}
		}

		cout << low << ' ' << high << ' ' << num << ' ' << empty << endl;

		
	}




	return 0;
}