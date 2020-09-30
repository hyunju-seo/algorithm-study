#include<iostream>
#include<queue>
#include<tuple>
#include<vector>
#include<algorithm>
using namespace std;

const int morning = 0;
const int night = 1;
int map[1002][1002];
int visited[1002][1002][12][2];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j] - '0';

		}

	}
	queue<tuple<int, int, int, int>> que;
	que.push(make_tuple(0, 0, 0, morning));
	visited[0][0][0][morning] = 1;
	int x, y, z, t;
	while (!que.empty()) {
		tie(x, y, z, t) = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nextx = x + dx[i];
			int nexty = y + dy[i];
			int nextt = (t + 1) % 2;
			if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m) continue;
			if (map[nextx][nexty] == 1) {
				if (z + 1 > k) continue;
				if (t == night) {
					if(!visited[x][y][z][nextt]){
						visited[x][y][z][nextt] = visited[x][y][z][t] + 1;
						que.push(make_tuple(x, y, z, nextt));
					}


				}
				else if (!visited[nextx][nexty][z + 1][nextt]) {

					visited[nextx][nexty][z + 1][nextt] = visited[x][y][z][t] + 1;
					que.push(make_tuple(nextx, nexty, z + 1, nextt));
				}
			}
			else {
				if (!visited[nextx][nexty][z][nextt]) {
					visited[nextx][nexty][z][nextt] = visited[x][y][z][t] + 1;
					que.push(make_tuple(nextx, nexty, z, nextt));
				}
			}
		}
	}
	vector<int> answers;
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j < 2; j++) {

			if (visited[n - 1][m - 1][i][j] == 0) continue;
			else answers.push_back(visited[n - 1][m - 1][i][j]);
		}
	}
	if (answers.empty()) cout << -1 << "\n";
	else cout << *min_element(answers.begin(), answers.end());
}