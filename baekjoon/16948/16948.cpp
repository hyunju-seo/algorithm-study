#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
int n;
int dx[] = { -2,-2,0,0,2,2 };
int dy[] = { -1,1,-2,2,-1,1 };
int dist[220][220];
int main() {
	memset(dist, -1, sizeof(dist));
	cin >> n;
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	queue<pair<int,int>>que;
	que.push({ r1,c1 });
	dist[r1][c1] = 0;
	while (!que.empty()) {
		int r = que.front().first;
		int c = que.front().second;
		que.pop();
		for (int i = 0; i <sizeof(dx)/sizeof(int); i++) {
			int nr = r + dx[i];
			int nc = c + dy[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
			if (dist[nr][nc] != -1) continue;
			dist[nr][nc] = dist[r][c] + 1;
			que.push({ nr,nc });

		}
	}
	cout << dist[r2][c2]<<"\n";
}