#include<iostream>
#include<vector>

using namespace std;
int board[20][20];
bool row[20][20];
bool col[20][20];
bool rec[20][20];
int group[20][20];
bool sdoku(int x, int y) {
	if (x >= 9) {  return true; }
	int dx = x;
	int dy = y + 1;
	if (dy + 1 > 9) {
		dy = 0;
		dx = x + 1;

	}
	if (board[x][y] != 0) return sdoku(dx, dy);
		
	for (int i = 1; i <= 9; i++) {
		if (row[x][i]) continue;
		if (col[y][i]) continue;
		if (rec[group[x][y]][i])continue;
		
		board[x][y] = i;
		row[x][i] = true;
		col[y][i] = true;
		rec[group[x][y]][i] = true;
		if (sdoku(dx, dy)) return true;
		board[x][y] = 0;
		row[x][i] = false;
		col[y][i] = false;
		rec[group[x][y]][i] = false;
	}

	return false;

}


int main() {
	for (int x = 0; x < 9; x++) {
		for (int y = 0; y < 9; y++) {
			if (x < 3) {
				if (y < 3) group[x][y] = 0;
				if (3 <= y && y < 6)group[x][y] = 1;
				if (6 <= y && y < 9)group[x][y] = 2;
			}
			if (3 <= x && x < 6) {
				if (y < 3) group[x][y] = 3;
				if (3 <= y && y < 6)group[x][y] = 4;
				if (6 <= y && y < 9)group[x][y] = 5;
			}
			if (6 <= x && x < 9) {
				if (y < 3) group[x][y] = 6;
				if (3 <= y && y < 6)group[x][y] = 7;
				if (6 <= y && y < 9)group[x][y] = 8;
			}

		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			rec[group[i][j]][board[i][j]] = true;
			row[i][board[i][j]] = true;
			col[j][board[i][j]] = true;

		}
		
	}
	sdoku(0, 0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << " ";
		}cout << endl;
	}

}