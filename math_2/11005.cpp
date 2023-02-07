#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, b;
    vector<char> cr;
    char a[36]; //0,1,2..9,A,B


    for (int i = 0; i <= 35; i++) {
        if (i < 10) {
            a[i] = i + 48;
        }
        else {
            a[i] = i + 55;
        }
    }

    cin >> n >> b;

    while (n != 0) {

        cr.push_back(a[n % b]);
        n /= b;
    }

    reverse(cr.begin(), cr.end());

    //end는 마지막의 다음 위치를 가리킴
    for (auto i = cr.begin(); i < cr.end(); i++) {
        cout << *i;
    }

    return 0;
}