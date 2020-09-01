#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<tuple>

using namespace std;
int map[1005][1005];
int visited[1005][1005][2];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;

void bfs(int x, int y) {
	queue<tuple<int, int , int>> que;
	que.push(make_tuple(x,y,0));
	visited[x][y][0] = 1;
	while (!que.empty()) {
		int num;
		tie( x, y, num) = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nextx = x + dx[i];
			int nexty = y + dy[i];
			if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m) continue;
			if (map[nextx][nexty] == 1) {
				if (num == 0) {
					if (visited[nextx][nexty][num+1] == 0) {

						que.push(make_tuple(nextx, nexty, num + 1));
						visited[nextx][nexty][num + 1] = visited[x][y][num] + 1;
					}
				}
			}
			else if (visited[nextx][nexty][num] == 0) {
				que.push(make_tuple(nextx, nexty, num));
				visited[nextx][nexty][num] = visited[x][y][num]+1;
			}
			/*if (map[nextx][nexty] == 0 && visited[nextx][nexty][num] == 0) {
				visited[nextx][nexty][num] = visited[x][y][num] + 1;
				que.push(make_tuple(nextx, nexty, num));
			}
			if (num == 0 && map[nextx][nexty] == 1 && visited[nextx][nexty][num + 1] == 0) {
				visited[nextx][nexty][num + 1] = visited[x][y][num] + 1;
				que.push(make_tuple(nextx, nexty, num + 1));
			}*/
		}
	}

}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	bfs(0, 0);
	if (visited[n - 1][m - 1][0] != 0 && visited[n - 1][m - 1][1] != 0) {
		cout << min(visited[n - 1][m - 1][0], visited[n - 1][m - 1][1]);
	}
	else if (visited[n - 1][m - 1][0] != 0) {
		cout << visited[n - 1][m - 1][0];
	}
	else if (visited[n - 1][m - 1][1] != 0) {
		cout << visited[n - 1][m - 1][1];
	}
	else {
		cout << -1;
	}
	cout << '\n';

}