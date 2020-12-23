#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<set>
#include<cstring>

using namespace std;
int map[1002][1002];
int group[1002][1002];
bool visited[1002][1002];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;
vector<int> group_idx;
void bfs(int x, int y, int gnum) {
	queue<pair<int, int>> que;
	group[x][y] = gnum;
	que.push({ x,y });
	int cnt = 1;
	visited[x][y] = true;
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nextx = x + dx[i];
			int nexty = y + dy[i];
			if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m) continue;
			if (map[nextx][nexty] == 1) continue;
			if (visited[nextx][nexty])continue;
			que.push({ nextx ,nexty });
			cnt += 1;
			group[nextx][nexty] = gnum;
			visited[nextx][nexty] = true;

		}
	}
	group_idx.push_back(cnt);
}

int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	int gnum = 0;
	memset(group, -1, sizeof(group));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0 && group[i][j] == -1) {
				bfs(i, j, gnum++);
			}
		}
	}

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << group[i][j] << " ";
	//	}cout << endl;
	//}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				set<int> near;

				for (int k = 0; k < 4; k++) {
					int nexti = i + dx[k];
					int nextj = j + dy[k];
					if (nexti < 0 || nexti >= n || nextj < 0 || nextj >= m) continue;
					if(map[nexti][nextj]==0) near.insert(group[nexti][nextj]);
				}
				int ans = 1;
				for (auto a : near) {
					ans += group_idx[a];
				}
				cout << ans % 10;
			}
			else {
				cout << 0;
			}
		}cout << endl;
	}
	
}