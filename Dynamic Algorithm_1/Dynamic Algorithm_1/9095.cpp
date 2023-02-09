#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	
	
	int t,n;
	cin >> t;
	while (t--)
	{
		cin >> n;

		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(4);


		for (int i = 3; i < n; i++)
		{
			v.push_back((v[i - 3] + v[i - 2] + v[i - 1]));

		}

		cout << v[n - 1] << '\n';
	}
	

	return 0;
}