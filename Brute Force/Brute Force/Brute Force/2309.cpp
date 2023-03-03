#include <iostream>
#include <algorithm>
using namespace std;

int human[10];
int main(int argc, char** argv) 
{
	
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> human[i];
		sum += human[i];
	}

	sort(human,human+9);

	for (int i = 0; i < 9; i++) {
		for (int j = i+1; j < 9; j++)
		{
			if ((sum - (human[i] + human[j])) == 100) {
				for (int k = 0; k < 9; k++) {
					if (i == k || j == k)
					{
						continue;
					}

					cout << human[k] << '\n';
					
				}

			}
			
		}
	}



}