#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
int arr[600][600];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int totalnum = 4;
int ans = -1;
bool visited[600][600];

void tetromino(int x, int y, int num, int sum) {
	vector<pair<int, int>> exceptions;

	if (num == totalnum) {
		ans = max(ans, sum);
		return;
	}

	visited[x][y] = true;


	for (int i = 0; i < 4; i++) {
		int newx = x + dx[i];
		int newy = y + dy[i];
		if (newx < 0 || newy < 0 || newx >= n || newy >= m) continue;
		if (visited[newx][newy] == false) {

			exceptions.push_back({ newx,newy });
			tetromino(newx, newy, num + 1, sum + arr[x][y]);
			visited[newx][newy] = false;
		}
	}
	if (num == 1) {
		for (int i = 0; i < exceptions.size(); i++) {
			for (int j = i + 1; j < exceptions.size(); j++) {

				ans = max(ans, sum + arr[x][y] + arr[exceptions[i].first][exceptions[i].second] + arr[exceptions[j].first][exceptions[j].second]);
			}
		}
	}
	visited[x][y] = false;


}



int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tetromino(i, j, 0, 0);
		}
	}

	cout << ans << "\n";
}