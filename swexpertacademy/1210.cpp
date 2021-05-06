#include<iostream>
#include<cstring>
using namespace std;
int board[102][102];
bool visited[102][102];
const int boardSize = 100;
int ans = -1;
bool rangeCheck(int idx) {
	if (idx >= boardSize) return false;
	if (idx < 0) return false;
	return true;
}
int ladderGO(int i, int j) {
	visited[i][j] = true;
	if (i == 0) {
		return j;
	}
	int ret;
	if (rangeCheck(j + 1) && !visited[i][j + 1] && board[i][j + 1] == 1) ret = ladderGO(i, j + 1);
	else if (rangeCheck(j - 1) && !visited[i][j - 1] && board[i][j - 1] == 1) ret = ladderGO(i, j - 1);
	else ret = ladderGO(i - 1, j);
	return ret;
}


int main(int argc, char** argv) {

	for (int t = 0; t < 10; t++) {
		int testNum;
		cin >> testNum;
		memset(visited, false, sizeof(visited));
		memset(board, 0, sizeof(board));
		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {
				cin >> board[i][j];
			}
		}
		for (int j = 0; j < boardSize; j++) {
			if (board[boardSize - 1][j] == 2) {
				ans = ladderGO(boardSize - 1, j);
				break;
			}
		}



		cout << "#" << testNum << " " << ans << "\n";
	}
	return 0;
}