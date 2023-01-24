#include <iostream>	
#include <string>
#define MAX_ARR_SIZE 26
using namespace std;


int main(int argc, char** argv) {
	int arr[MAX_ARR_SIZE] = { 0 };
	string str;
	char cr;

	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		cr = str[i];
		arr[cr - 97] += 1;
	}

	for (int i = 0; i < MAX_ARR_SIZE; i++) {
		cout << arr[i] << ' ';
	}
	
	
	return 0;
}