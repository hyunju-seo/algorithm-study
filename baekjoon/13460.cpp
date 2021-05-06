#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

char map[11][11];
int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };

struct Pos {
	int x; int y;
};
int cnt[11][11][11][11];
bool visited[11][11][11][11];
int bfs(int rx, int ry, int bx, int by) {
	memset(cnt, -1, sizeof(cnt));
	cnt[rx][ry][bx][by] = 0;
	queue<pair<Pos, Pos>> que;
	que.push({ { rx, ry }, { bx, by } });
	while (!que.empty()) {
		rx = que.front().first.x;
		ry = que.front().first.y;
		bx = que.front().second.x;
		by = que.front().second.y;
		visited[rx][ry][bx][by] = true;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nrx = rx;
			int nry = ry;
			int nbx = bx;
			int nby = by;
			while (true) {
				if (map[nrx][nry] == 'O') break;
				if (map[nrx + dx[i]][nry + dy[i]] == '#') break;

				nrx = nrx + dx[i];
				nry = nry + dy[i];
			}
			while (true) {
				if (map[nbx][nby] == 'O') break;
				if (map[nbx + dx[i]][nby + dy[i]] == '#') break;

				nbx = nbx + dx[i];
				nby = nby + dy[i];
			}
			if (nrx == nbx && nry == nby && map[nrx][nry] != 'O') {
				if (i == 0) {
					if (ry > by) nry += 1;
					else nby += 1;
				}
				else if (i == 1) {
					if (ry > by) nby -= 1;
					else nry -= 1;
				}
				else if (i == 2) {
					if (rx > bx) nbx -= 1;
					else nrx -= 1;
				}
				else {
					if (rx > bx) nrx += 1;
					else nbx += 1;
				}
			}
			if (nrx == rx && nry == ry && nbx == bx && nby == by) continue;
			if (map[nrx][nry] == 'O' && map[nbx][nby] == 'O') continue;
			if (visited[nrx][nry][nbx][nby]) continue;
			if (cnt[nrx][nry][nbx][nby] != -1)	cnt[nrx][nry][nbx][nby] = min(cnt[rx][ry][bx][by] + 1, cnt[nrx][nry][nbx][nby]);
			else cnt[nrx][nry][nbx][nby] = cnt[rx][ry][bx][by] + 1;
			if (cnt[nrx][nry][nbx][nby] > 10)continue;

			que.push({ {nrx, nry}, {nbx, nby} });
			
			if (map[nrx][nry] == 'O' && map[nbx][nby] != 'O') {
				return cnt[nrx][nry][nbx][nby];
			}
		}

	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int rx, ry, bx, by;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j];
			
			if (map[i][j] == 'R') {
				rx = i;
				ry = j;
			}
			else if (map[i][j] == 'B') {
				bx = i;
				by = j;				

			}
	
		}


	}
	cout<< bfs(rx, ry, bx, by);
	
	
}
