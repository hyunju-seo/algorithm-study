#include<iostream>
#include<queue>
#include<tuple>
#include<vector>
#include<algorithm>

using namespace std;
int map[1002][1002];
int visited[1002][1002][12];
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
	queue<tuple<int,int,int>> que;
	que.push(make_tuple(0, 0, 0));
	visited[0][0][0] = 1;
	int x, y, z;
	while (!que.empty()) {
		tie(x, y, z) = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nextx = x + dx[i];
			int nexty = y + dy[i];
			if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m) continue;
			if (map[nextx][nexty] == 1) {
				if (z + 1 > k) continue;
				if (!visited[nextx][nexty][z + 1]) {

					visited[nextx][nexty][z + 1] = visited[x][y][z] + 1;
					que.push(make_tuple(nextx, nexty, z + 1));
				}
				}
			else {
				if (!visited[nextx][nexty][z]) {
					visited[nextx][nexty][z] = visited[x][y][z] + 1;
					que.push(make_tuple(nextx, nexty, z));
				}
			}
		}
	}
	vector<int> answers;
	for (int i = 0; i <= k; i++) {
		if (visited[n - 1][m - 1][i] == 0) continue;
		else answers.push_back(visited[n - 1][m - 1][i]);

	}
	if (answers.empty()) cout << -1 << "\n";
	else cout << *min_element(answers.begin(), answers.end());
}