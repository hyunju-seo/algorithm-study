#include<iostream>
#include<vector>

using namespace std;
int map[21][21];
int dx[] = {0, 0, 0, -1, 1};
int dy[] = { 0, 1, -1, 0, 0 };
int dice[7];
int main() {
	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	vector<int> move(k);
	for (int i = 0; i < k; i++) cin >> move[i];
	
	
	for (auto di : move) {
		int nextx = x + dx[di];
		int nexty = y + dy[di];
		if (nextx >= n || nexty >= m || nextx < 0 || nexty < 0) continue;
		int d1 = dice[1], d2 = dice[2], d3 = dice[3], d4 = dice[4], d5 = dice[5], d6 = dice[6];
		if (di == 1) { // 悼率
			dice[1] = d3;
			dice[3] = d6;
			dice[6] = d4;
			dice[4] = d1;
		}
		else if (di == 2) {//辑率
			dice[1] = d4;
			dice[3] = d1;
			dice[6] = d3;
			dice[4] = d6;
		}
		else if (di == 3) { //合率
			dice[1] = d2;
			dice[2] = d6;
			dice[5] = d1;
			dice[6] = d5;
		}
		else if (di == 4) {//巢率
			dice[1] = d5;
			dice[5] = d6;
			dice[6] = d2;
			dice[2] = d1;
		}
		x = nextx;
		y = nexty;

		if (map[x][y] == 0) {
			map[x][y] = dice[6];
		}
		else {
			dice[6] = map[x][y];
			map[x][y] = 0;
		}
		cout << dice[1]<< "\n";
	}


}