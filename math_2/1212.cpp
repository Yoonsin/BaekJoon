#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {

    string str = "";
    string oct;
    cin >> oct;

    for (int i = 0; i < oct.length(); i++) {
        int num = oct[i] - '0';
        str += num / 4 + '0';
        str += num % 4 / 2 + '0';
        str += num % 4 % 2 / 1 + '0';
    }

    while (true) {
        if (str[0] == '1' || str.length() == 1)
            break;
        else
            str.erase(0, 1);
    }


    cout << str;

    return 0;
}