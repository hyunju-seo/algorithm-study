#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
int map[101][101];
int group[101][101];
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n;
int bridge[101][101];
void bfs(int x, int y, int groupnum) {
	group[x][y] = groupnum;
	queue<pair<int, int>> que;
	que.push({ x,y });
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nextx = x + dx[i];
			int nexty = y + dy[i];
			if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= n) continue;
			if (map[nextx][nexty] != 1) continue;
			if (group[nextx][nexty] != 0) continue;
			group[nextx][nexty] = groupnum;
			que.push({ nextx, nexty });
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	int groupNum = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && group[i][j] == 0) {
				bfs(i, j, groupNum);
				groupNum += 1;
			}
		}
	}
	int ans = 1000000000;
	for (int g = 1; g <= groupNum; g++) {
		queue<pair<int, int>> bq;
		memset(bridge, 0, sizeof(bridge));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (group[i][j] == g) {
					for (int t = 0; t < 4; t++) {
						int nextx = i + dx[t];
						int nexty = j + dy[t];
						if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= n) continue;
						if (map[nextx][nexty] == 1) continue;
						bq.push({ nextx, nexty });
						bridge[nextx][nexty] = 1;

					}
				}
			}
		}

		while (!bq.empty()) {
			int x = bq.front().first;
			int y = bq.front().second;
			bq.pop();
			for (int i = 0; i < 4; i++) {
				int nextx = x + dx[i];
				int nexty = y + dy[i];
				if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= n) continue;
				if (map[nextx][nexty] == 1) {
					if (group[nextx][nexty] != g) {
						ans = min(ans, bridge[x][y]);
					}
					continue;
				}
				if (bridge[nextx][nexty] != 0) continue;
				bridge[nextx][nexty] = bridge[x][y] + 1;
				bq.push({ nextx, nexty });
			}
		}

	}

	cout << ans << "\n";
}