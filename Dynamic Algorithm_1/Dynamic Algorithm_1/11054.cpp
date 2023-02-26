#include <iostream>
#define MAX 1000
using namespace std;

int arr[MAX + 1]; 

int add_dp[MAX + 1]; //���� �� ���� �κ� ����
int sub_dp[MAX + 1]; //���� �� ���� �κ� ����

int main(int argc, char** argv) 
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int max_num = 0;

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= i; j++) {
			if (arr[i] > arr[j]) {
				if (add_dp[i] < add_dp[j]) {
					add_dp[i] = add_dp[j];
				}
			}
		}
		add_dp[i] += 1;	
	}

	for (int i = n; i >= 1; i--) {
		for (int j = n; j >= i; j--) {
			if (arr[i] > arr[j]) {
				if (sub_dp[i] < sub_dp[j]) {
					sub_dp[i] = sub_dp[j];
				}
			}
		}
		sub_dp[i] += 1;

		
        //����&���� ���� ���̿��� arr[i]�� �ߺ��ǹǷ� 1�� ���ش�
		max_num = max(max_num, add_dp[i] + sub_dp[i] - 1);
	}


	cout << max_num;


	return 0;
}