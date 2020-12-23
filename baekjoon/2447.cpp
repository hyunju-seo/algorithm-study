#include<iostream>
using namespace std;
int printstar[7000][7000];
#define STAR 1
#define BLANK 0
void func(int x, int y, int n, int shape) {
	if (shape == BLANK) {
		for (int i= x; i < x + n; i++) {
			for (int j = y; j < y + n; j++) {
				printstar[i][j] = BLANK;
			}
		
		}
		return;
	}
	if (n == 3) {
		for (int i = x; i < x+3; i++) {
			for (int j = y; j < y+3; j++) {
				if (i == x + 1 && j == y + 1) printstar[i][j] = BLANK;
				else printstar[i][j] = STAR; //여기 찾기
			}
		}
		return;
	}
	int m = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) {
				//blank
				func(x + m * i, y + m * j, m, BLANK);
			}
			else {
				//blank x
				func(x + m * i, y + m * j, m, STAR);

			}

		}
	}
	

}


int main() {
	int n;
	cin >> n;
	func(0, 0, n, STAR);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (printstar[i][j] == STAR) {
				cout << "*";
			}
			else {
				cout << " ";
			}
			//cout << printstar[i][j] << " ";
		}cout << "\n";
	}
}