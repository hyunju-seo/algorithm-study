#include<string>
#include<cstring>
#include<iostream>
using namespace std;
int n, m;
string board[55];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int dist[55][55];       //시작점에서 x,y까지 거리(최단 거리가 아님)
bool check[55][55];     //x,y를 방문했는지 여부
bool dfs(int x, int y, int cnt, char color) {  //cnt 방문한 점의 개수
	if (check[x][y]) {
		if (cnt - dist[x][y] >= 4) return true;
		else return false;
	}

	check[x][y] = true;
	dist[x][y] = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m && color==board[nx][ny]) {
			if (dfs(nx, ny, cnt + 1, color)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
			cin >> board[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j]) continue;
			memset(dist, 0, sizeof(dist));
			bool ok = dfs(i, j, 1, board[i][j]);
			if (ok) {
				cout << "Yes" << "\n";
				return 0;
			}
		}
	}
	cout << "No" << "\n";
	return 0;

}