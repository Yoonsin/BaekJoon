#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
	int e, s, m;
	cin >> e >> s >> m;
	int years = 0;
	int earth = 0;  int sun = 0; int moon = 0;

	while (true)
	{
		years += 1;
		
		earth += 1; if (earth == 16) earth = 1;
		sun += 1; if (sun == 29) sun = 1;
		moon += 1; if (moon == 20) moon = 1;

		if (earth == e && sun == s && moon == m)
			break;
		
	}

	cout << years;

	return 0;
}