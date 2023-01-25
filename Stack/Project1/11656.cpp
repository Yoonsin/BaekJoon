#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
	
	vector<string> v;
	
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		v.push_back(str.substr(i, str.size() - i));
	}

	sort(v.begin(), v.end());

	vector<string>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		cout << *it  << endl;
	}
	
	
	return 0;
}