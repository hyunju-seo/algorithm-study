#include<iostream>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int input;
	cin >> input;
	long fac = 1;
	int zero_num = 0;

	for (int i = 1; i <= input; i++) {
		int num = i;
		while (num % 5 == 0) {
			zero_num++;
			num = num / 5;
		}
	}
	
	cout << zero_num;
}