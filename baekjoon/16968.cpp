#include<iostream>

using namespace std;
int const number = 1;
int const alphabet = 0;
int num = 10;
int alpha = 26;
int main() {
	string str;
	cin >> str;
	int before = -1;
	int ans = 1;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'd') {
			if (before == number) {
				ans *= (num-1);
			}
			else {
				ans *= num;
				
			}
			before = number;
		}
		else if (str[i] == 'c') {
			if (before == alphabet) {
				ans *= (alpha - 1);
			}
			else {
				ans *= alpha;
			}
			before = alphabet;
		}
	}
	cout << ans << "\n";
}