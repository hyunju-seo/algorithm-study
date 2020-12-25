#include<iostream>
#define STAR 1
#define BLANK 0
using namespace std;
int printstar[8000][8000];

void func(int x, int y, int n) {
	if (n == 3) {
		//세모모양 만들기
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j <= i; j++) {
				if (i == 1 && j == 0) {
					printstar[x + i][y] = BLANK;
				}
				else {
					printstar[x + i][y + j] = STAR;
					printstar[x + i][y - j] = STAR;
				}
			}
		}
		return;
	}
	int m = n / 2;
	func(x, y, m);
	func(x + m, y - m, m);
	func(x + m, y + m, m);
}

int main() {
	int n;
	cin >> n;
	func(0, n, n);
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < 2 * n; j++) {
			if (printstar[i][j] == STAR) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}cout << "\n";
	}
}