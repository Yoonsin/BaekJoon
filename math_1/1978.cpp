#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
	int t;	
	int num;
	int cnt = 0;
	bool flag;
	cin >> t;

	while (t--)
	{
		cin >> num;
		flag = false;

		for (int i = 2; i < num; i++) {
			if (num % i == 0) {
				flag = true; //¼Ò¼ö ¾Æ´Ô
				break;
			}
		}

		if (flag == false&&num!=1) {
			cnt+=1;
		}
			
	}

	cout << cnt;


	return 0;
}