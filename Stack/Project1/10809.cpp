#include <iostream>
#include <string>
#define MAX_ARR_SIZE 26
using namespace std;

int main(int argc, char** argv) {
	int arr[MAX_ARR_SIZE];

	for (int i = 0; i < MAX_ARR_SIZE; i++) {
		arr[i] = -1;
	}

	string str;

	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		
		if (arr[str[i] - 97] == -1)
			arr[str[i] - 97] = i;
	}

	for (int i = 0; i < MAX_ARR_SIZE; i++) {
		cout << arr[i] << ' ';
	}

	return 0;

}