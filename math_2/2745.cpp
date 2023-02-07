#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main (int argc, char** argv) {

	string str;
	int b;
	int sum = 0;

	cin >> str >> b;
	
	//인덱스가 오른쪽 끝자리 부터 시작할 수 있도록 바꿔주기 
	reverse(str.begin(), str.end()); 
	
	for (int i = 0; i< str.size(); i++) 
	{
		char cr = str[i];
		if (cr >= 'A') {
			//알파벳
			sum += pow(b, i) * (cr - 'A' + 10);
			//(진법^자리) * (현재 자릿수)  
			
		}
		else {
			//0~9까지 숫자
			sum += pow(b, i) * (cr - '0');
		}

	}

	cout << sum;

	
	return 0;
}