#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>

using namespace std;
int maze[101][101];
int dist[101][101];
bool visited[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;
struct Node {
	int x;
	int y;
	int dist;
	bool operator < (const Node& other) const {
		return dist > other.dist;
	}
};
bool rangeCheck(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) return false;
	return true;
}
int main() {

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &maze[i][j]);
			dist[i][j] =1000000000;
		}
	}


	priority_queue<Node> que;
	que.push({ 0,0,0 });
	dist[0][0] = 0;
	while (!que.empty()) {
		int x = que.top().x;
		int y = que.top().y;
		int distance = que.top().dist;
		//cout << x << "  " << y << endl;
		que.pop();
		if (visited[x][y]) continue;
		visited[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int nextx = x + dx[i];
			int nexty = y + dy[i];
			if (!rangeCheck(nextx, nexty)) continue;
			if (maze[nextx][nexty] == 0) {
				if (dist[nextx][nexty] > distance) {
					dist[nextx][nexty] = distance;
					que.push({ nextx, nexty,distance });

				}
			}
			else {
				if (dist[nextx][nexty] > distance+1) {
					dist[nextx][nexty] = distance+1;
					que.push({ nextx, nexty,distance+1 });

				}

			}

		}
	}
	cout << dist[n - 1][m - 1];
}