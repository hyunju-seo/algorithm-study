#include<iostream>
using namespace std;
char arr[55][55];

void solution(int r, int c, int zr, int zc) {
	for (int i = 0; i < r; i++) {
		for (int ir = 0; ir < zr; ir++) {
			for (int j = 0; j < c; j++) {
				for (int jc = 0; jc < zc; jc++) {
					cout << arr[i][j];
				}
			}
			cout << "\n";
		}
	}
}
int main() {
	int r, c, zr, zc;
	cin >> r >> c >> zr >> zc;
	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < c; j++) {
			arr[i][j] = s[j];
		}
	}
	solution(r, c, zr, zc);
}