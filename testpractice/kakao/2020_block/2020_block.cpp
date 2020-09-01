#include <string>
#include <vector>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };
int visited[104][104][104][104];
int dist[104][104][104][104];
struct position {
	int x1, y1, x2, y2;
};
void visit(position po) {
	visited[po.x1][po.y1][po.x2][po.y2] = true;
}

int solution(vector<vector<int>> board) {
	memset(dist, -1, sizeof(dist));

	int n = board[0].size();
	position po = { 1,1,1,2 };
	queue<position> que;
	que.push(po);
	visit(po);
	dist[po.x1][po.y1][po.x2][po.y2] = 0;
	while (!que.empty()) {

		int x1 = que.front().x1;
		int y1 = que.front().y1;
		int x2 = que.front().x2;
		int y2 = que.front().y2;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nextx1 = x1 + dx[i];
			int nexty1 = y1 + dy[i];
			int nextx2 = x2 + dx[i];
			int nexty2 = y2 + dy[i];
			if (nextx1 < 1 || nextx1 >= n + 1 || nextx2 < 1 || nextx2 >= n + 1 || nexty1 < 1 || nexty1 >= n + 1 || nexty2 < 1 || nexty2 >= n + 1) continue;
			if (visited[nextx1][nexty1][nextx2][nexty2]) continue;
			if (board[nextx1][nexty1] == 0 && board[nextx2][nexty2] == 0) {
				position po = { nextx1, nexty1, nextx2, nexty2 };
				que.push(po);
				visit(po);
				dist[nextx1][nexty1][nextx2][nexty2] = dist[x1][y1][x2][y2] + 1;
			}
		}
		if (x1 + 1 < n + 1 && x2 + 1 < n + 1) {
			if (board[x1 + 1][y1] == 0 && board[x2 + 1][y2] == 0) {
				int nextx1 = x1;
				int nexty1 = y1;
				int nextx2 = x2 + 1;
				int nexty2 = y2 - 1;
				if (!visited[nextx1][nexty1][nextx2][nexty2]) {
					position po = { nextx1, nexty1, nextx2, nexty2 };
					que.push(po);
					visit(po);
					dist[nextx1][nexty1][nextx2][nexty2] = dist[x1][y1][x2][y2] + 1;

				}
				nextx1 = x1 + 1;
				nexty1 = y1 + 1;
				nextx2 = x2;
				nexty2 = y2;
				if (!visited[nextx1][nexty1][nextx2][nexty2]) {
					position po = { nextx1, nexty1, nextx2, nexty2 };
					que.push(po);
					visit(po);
					dist[nextx1][nexty1][nextx2][nexty2] = dist[x1][y1][x2][y2] + 1;

				}
			}

		}
		if (x1 - 1 >= 1 && x2 - 1 >= 1) {
			if (board[x1 - 1][y1] == 0 && board[x2 - 1][y2] == 0) {
				int nextx1 = x1;
				int nexty1 = y1;
				int nextx2 = x2 - 1;
				int nexty2 = y2 - 1;
				if (!visited[nextx1][nexty1][nextx2][nexty2]) {
					position po = { nextx1, nexty1, nextx2, nexty2 };
					que.push(po);
					visit(po);
					dist[nextx1][nexty1][nextx2][nexty2] = dist[x1][y1][x2][y2] + 1;

				}
				nextx1 = x1 - 1;
				nexty1 = y1 + 1;
				nextx2 = x2;
				nexty2 = y2;
				if (!visited[nextx1][nexty1][nextx2][nexty2]) {
					position po = { nextx1, nexty1, nextx2, nexty2 };
					que.push(po);
					visit(po);
					dist[nextx1][nexty1][nextx2][nexty2] = dist[x1][y1][x2][y2] + 1;

				}
			}

		}
		if (y1 - 1 >= 1 && y1 - 1 >= 1) {
			if (board[x1][y1 - 1] == 0 && board[x2][y2 - 1] == 0) {
				int nextx1 = x1;
				int nexty1 = y1;
				int nextx2 = x2 - 1;
				int nexty2 = y2 - 1;
				if (!visited[nextx1][nexty1][nextx2][nexty2]) {
					position po = { nextx1, nexty1, nextx2, nexty2 };
					que.push(po);
					visit(po);
					dist[nextx1][nexty1][nextx2][nexty2] = dist[x1][y1][x2][y2] + 1;

				}
				nextx1 = x1 + 1;
				nexty1 = y1 - 1;
				nextx2 = x2;
				nexty2 = y2;
				if (!visited[nextx1][nexty1][nextx2][nexty2]) {
					position po = { nextx1, nexty1, nextx2, nexty2 };
					que.push(po);
					visit(po);
					dist[nextx1][nexty1][nextx2][nexty2] = dist[x1][y1][x2][y2] + 1;

				}
			}

		}
		if (y1 + 1 < n + 1 && y1 + 1 < n + 1) {
			if (board[x1][y1 + 1] == 0 && board[x2][y2 + 1] == 0) {
				int nextx1 = x1;
				int nexty1 = y1;
				int nextx2 = x2 - 1;
				int nexty2 = y2 + 1;
				if (!visited[nextx1][nexty1][nextx2][nexty2]) {
					position po = { nextx1, nexty1, nextx2, nexty2 };
					que.push(po);
					visit(po);
					dist[nextx1][nexty1][nextx2][nexty2] = dist[x1][y1][x2][y2] + 1;

				}
				nextx1 = x1 + 1;
				nexty1 = y1 + 1;
				nextx2 = x2;
				nexty2 = y2;
				if (!visited[nextx1][nexty1][nextx2][nexty2]) {
					position po = { nextx1, nexty1, nextx2, nexty2 };
					que.push(po);
					visit(po);
					dist[nextx1][nexty1][nextx2][nexty2] = dist[x1][y1][x2][y2] + 1;

				}
			}

		}

	}
	int answer = 0;
	if (dist[n - 1][n][n][n] == -1) answer = dist[n][n - 1][n][n];
	else if (dist[n][n - 1][n][n] == -1) answer = dist[n - 1][n][n][n];
	else answer = min(dist[n][n - 1][n][n], dist[n - 1][n][n][n]);
	return answer;
}