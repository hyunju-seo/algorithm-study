#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int baduk[21][21];
int group[21][21];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
bool inserted[21][21];
int n, m;
vector<pair<int, int>> zeroPos[401];
int groupNum[401];
struct pos {
	int x;
	int y;
};


int check(int groupnum) {

	for (auto z : zeroPos[groupnum]) {
		if (baduk[z.first][z.second] == 0) return 0;

	}
	return groupNum[groupnum];
}

void bfs(int groupnum, int x, int y) {
	queue<pair<int, int>> que;
	group[x][y] = groupnum;
	que.push({ x, y });
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int td = 0; td < 4; td++) {
			int tnextx = x + dx[td];
			int tnexty = y + dy[td];
			if (tnextx < 0 || tnexty < 0 || tnextx >= n || tnexty >= m) continue;
			if (baduk[tnextx][tnexty] == 0) zeroPos[groupnum].push_back({ tnextx, tnexty });
		}
		groupNum[groupnum] += 1;
		for (int i = 0; i < 4; i++) {
			int nextx = x + dx[i];
			int nexty = y + dy[i];
			if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= m) continue;
			if (group[nextx][nexty] != 0) continue;
			if (baduk[nextx][nexty] != 2)continue;
			group[nextx][nexty] = groupnum;
			que.push({ nextx, nexty });

		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> baduk[i][j];
		}
	}
	int groupnum = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (baduk[i][j] == 2 && group[i][j] == 0) {
				bfs(groupnum, i, j);
				groupnum += 1;
			}
		}
	}

	vector<pos> emptyPos;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (baduk[i][j] == 2) {
				for (int t = 0; t < 4; t++) {
					int nextx = i + dx[t];
					int nexty = j + dy[t];
					if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= m) continue;
					if (baduk[nextx][nexty] == 0 && !inserted[nextx][nexty]) {
						inserted[nextx][nexty] = true;
						emptyPos.push_back({ nextx, nexty });
					}
				}

			}
		}
	}

	int ans = 0;
	int esize = emptyPos.size();
	for (int i = 0; i < esize; i++) {
		for (int j = i; j < esize; j++) {
			baduk[emptyPos[i].x][emptyPos[i].y] = 1;
			baduk[emptyPos[j].x][emptyPos[j].y] = 1;
			int sum = 0;
			for (int t = 1; t < groupnum; t++) {
				sum += check(t);
			}
			ans = max(sum, ans);
			baduk[emptyPos[i].x][emptyPos[i].y] = 0;
			baduk[emptyPos[j].x][emptyPos[j].y] = 0;
		}
	}
	cout << ans << "\n";
}