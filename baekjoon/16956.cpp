//https://www.acmicpc.net/problem/16956
#include<iostream>
#include<queue>

using namespace std;
const char sheep = 'S';
const char wolf = 'W';
const char fence = 'D';
const char non = '.';
char board[501][501];
int r, c;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool visited[501][501] = { false };

bool eatSheep(int x, int y) {
	queue<pair<int, int>> que;
	que.push({ x,y });
	visited[x][y] = true;
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nextx = x + dx[i];
			int nexty = y + dy[i];
			if (nextx < 0 || nexty < 0 || nextx >= r || nexty >= c) continue;
			if (board[nextx][nexty] == sheep) return true;
			if (visited[nextx][nexty]) continue;
			if (board[nextx][nexty] != non) continue;
			visited[nextx][nexty] = true;
			que.push({ nextx,nexty });
		}
	}
	return false;


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == sheep || board[i][j] == wolf) {
				for (int ro = 0; ro < 4; ro++) {
					int nextx = i + dx[ro];
					int nexty = j + dy[ro];
					if (nextx < 0 || nexty < 0 || nextx >= r || nexty >= c) continue;
					if (board[nextx][nexty] != non) continue;
					board[nextx][nexty] = fence;
				}
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == wolf) {
				if (eatSheep(i, j)) {
					cout << 0 << "\n";
					return 0;

				}
			}
		}
	}
	cout << 1 << "\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << board[i][j];
		}cout << "\n";
	}
	return 0;
	

}