// https://www.acmicpc.net/problem/4963
//지도 너비 w 높이 h (w<=50, h<=50)
//땅 1, 바다 0
//섬의 개수 출력
#include<iostream>
#include<queue>
using namespace std;

int map[60][60];
int dx[8] = { 0, 1, -1, 0, 1, -1, 1, -1 };
int dy[8] = { 1, 0, 0, -1, 1, -1, -1, 1 };

void bfs(int x, int y, int w, int h) {
	queue<pair<int,int>> que;
	que.push({ x,y });
	map[x][y] = 2;
	while (!que.empty()) {
		x = que.front().first;
		y = que.front().second;

		que.pop();
		for (int i = 0; i < 8; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];

			if (nextX >= 0 && nextX < h && nextY >= 0 && nextY < w) {
				if (map[nextX][nextY] == 1) {
					map[nextX][nextY] = 2;
					que.push({ nextX,nextY });
				}
			}
		}
	}
}

int main() {
	while (true) {
		int w, h;
		cin >> w >> h;
		if (w == 0 && h == 0) return 0;
		int ans = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1) {
					bfs(i, j, w, h);
					ans++;
				}
			}
		}
		cout << ans << "\n";
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				map[i][j] = 0;
			}
		}
	}
	return 0;
}