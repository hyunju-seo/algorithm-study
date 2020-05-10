// https://www.acmicpc.net/problem/7576//gk
//하루가 지나면 익은 토마토 위, 아래 가 모두 익음
//며칠이 지나면 다 익게 될까
////1 익음, 0 안익음, -1 토마토 없음

#include<iostream>
#include<queue>

using namespace std;

int box[1005][1005];
int dx[] = {0, 1, -1, 0 };
int dy[] = { 1, 0, 0, -1 };
int day[1005][1005];


int main() {
	queue<pair<int, int>> que;
	int ans;
	int m, n;

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				que.push({ i,j });
				day[i][j] = 0;
		}
	}
	int x, y;

	while (!que.empty()) {
		x = que.front().first;
		y = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (nextX >= 0 && nextY >= 0 && nextX < n && nextY < m) {
				if (box[nextX][nextY] == 0) {
					day[nextX][nextY] = day[x][y] + 1;
					box[nextX][nextY] = 1;
					que.push({ nextX,nextY });
				}
			}

		}
		if (que.empty()) {
			ans = day[x][y];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 0) {
				cout << -1 << "\n";
				return 0;
			}
		}
	}	cout << ans << "\n";
}