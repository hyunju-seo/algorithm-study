// https://www.acmicpc.net/problem/2178
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

#include<queue>
using namespace std;
int n, m;
int dx[] = {0, 1,-1, 0 };
int dy[] = {1, 0, 0, -1 };
int dist[110][110]; //몇 번째 스텝인지
int maze[110][110];//2 방문 완료한 곳, 1은 갈 수 있는 곳, 0은 갈 수 없는 곳 
void bfs(int x, int y) {
	int ans = 0;
	queue<pair<int,int>> que;
	maze[x][y] = 2;
	que.push({ x,y });
	dist[x][y] = 1;
	while (!que.empty()) {
		x = que.front().first;
		y = que.front().second;
		que.pop();
		bool step = false;
	
		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
				if (maze[nextX][nextY] == 1) {
					maze[nextX][nextY] = 2;
					que.push({ nextX,nextY });
					dist[nextX][nextY] = dist[x][y] + 1;
				}
			}


		}

	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}
	bfs(0, 0);
	cout << dist[n-1][m-1]<<endl;
}