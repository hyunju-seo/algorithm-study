#include<iostream>
#include<algorithm>

using namespace std;
int candy[1001][1001][3];
int map[1001][1001];
int dx[] = { 1,0,1 };
int dy[] = { 0,1,1 };
int n, m;
int d[1001][1001];

bool rangeCheck(int x, int y) {
	if (x >= n || y >= m || x < 0 || y < 0) return false;
	return true;

}

int func(int x, int y) {
	
	int ret = 0;
	if (d[x][y] != -1) return d[x][y];
	if (rangeCheck(x - 1, y - 1)) {
		ret=max(ret, func(x - 1, y - 1));

	}	
	if (rangeCheck(x - 1, y)) {
		ret = max(ret, func(x - 1, y));

	}	
	if (rangeCheck(x, y - 1)) {
		ret = max(ret, func(x, y - 1));

	}
	d[x][y] = ret + map[x][y];
	return d[x][y];

}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			d[i][j] = -1;
		}
	}
	candy[0][0][0] = map[0][0];
	candy[0][0][1] = map[0][0];
	candy[0][0][2] = map[0][0];
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 3; k++) {
				int nextX = i + dx[k];
				int nextY = j + dy[k];
				if (nextX >= n || nextY >= m || nextX < 0 || nextY < 0) continue;
				int temp = map[nextX][nextY]+max({ candy[i][j][0],candy[i][j][1],candy[i][j][2] });
				candy[nextX][nextY][k] =temp;
			}
		}
	}
	int ans = max({ candy[n - 1][m - 1][0], candy[n - 1][m - 1][1] , candy[n - 1][m - 1][2] });*/
	
	int ans = func(n-1, m-1);
	cout << ans << "\n";
}