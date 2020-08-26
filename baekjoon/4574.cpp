#include<iostream>
#include<cstring>
using namespace std;
int board[20][20];
bool domino[20][20];
bool col[20][20];
bool row[20][20];
bool rec[20][20];
int group(int x, int y) {
	return (x - 1) / 3 *3 + (y - 1) / 3;
}
int dx[] = { 0, 1 };
int dy[] = { 1, 0 };

bool sdoku(int x, int y) {
	//cout << "sdoku(" << x << ", " << y << ")" << endl;
	//정답찾은경우
	if (x > 9) {   return true; }
	//다음칸 계산
	int nx = x;
	int ny = y + 1;
	if (y + 1 > 9) {
		ny = 1; //이걸 0으로 해서 틀림
		nx = x + 1;
	}
	if (board[x][y] != 0) {
		//cout << "pass" << endl;
		return sdoku(nx, ny);
	}
	for (int i = 0; i < 2; i++) {

		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX > 9 || nextX <= 0 || nextY > 9 || nextY <= 0) continue;

		if (board[nextX][nextY] != 0) continue;

		for (int j = 1; j <= 9; j++) {
			for (int k = 1; k <= 9; k++) {
				
				if (j == k) continue;
				if (domino[j][k] || domino[k][j])continue;
				if (col[y][k] || row[x][k] || rec[group(x, y)][k]) continue;
				if (col[nextY][j] || row[nextX][j] || rec[group(nextX, nextY)][j]) continue;
				
				board[x][y] = k;
				board[nextX][nextY] = j;
				domino[j][k] = domino[k][j] = true;
				col[y][k] = row[x][k] = rec[group(x, y)][k] = true;
				col[nextY][j] = row[nextX][j] = rec[group(nextX, nextY)][j] = true;
	/*			for (int idx = 1; idx <= 9; idx++) {
					for (int ix = 1; ix <= 9; ix++) {
						cout << board[idx][ix] << " ";
					}cout << endl;
				}*/

				if (sdoku(nx, ny)) return true;
				board[x][y] = 0;
				board[nextX][nextY] = 0;
				domino[j][k] = domino[k][j] = false;
				col[y][k] = row[x][k] = rec[group(x, y)][k] = false;
				col[nextY][j] = row[nextX][j] = rec[group(nextX, nextY)][j] = false;
			}
		}
	}
	return false;


}


int main() {
	int n;
	int num = 1;
	while (true) {

		cin >> n;
		if (n == 0) break;
		memset(board, 0, sizeof(board));
		memset(domino, 0, sizeof(domino));
		memset(col, 0, sizeof(col));
		memset(row, 0, sizeof(row));
		memset(rec, 0, sizeof(rec));

		for (int i = 0; i < n; i++) {
			int num1, num2;
			string po1, po2;
			cin >> num1 >> po1 >> num2 >> po2;
			domino[num1][num2] = domino[num2][num1] = true;
			board[po1[0] - 'A' + 1][po1[1] - '0'] = num1;
			board[po2[0] - 'A' + 1][po2[1] - '0'] = num2;

		}
		for (int i = 1; i <= 9; i++) {
			string po;
			cin >> po;
			board[po[0] - 'A' + 1][po[1] - '0'] = i;
		}


		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				row[i][board[i][j]] = true;
				col[j][board[i][j]] = true;
				rec[group(i,j)][board[i][j]] = true;
			}
		}

	


		sdoku(1, 1);


		cout << "Puzzle " << num << endl;
		num++;
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				cout << board[i][j];
			}cout << "\n";
		}



	}
	
}
