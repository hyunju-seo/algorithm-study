#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
int ne[105];
int dist[105];


int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < 103; i++) {
		ne[i] = i;

	}
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		ne[x] = y;

	}

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		ne[u] = v;
	}
	queue<int> que;
	que.push(1);
	dist[1] = 0;
	while (!que.empty()) {
		int f = que.front();
		que.pop();
		for (int i = 1; i <= 6; i++) {
			int y = f + i;
			if (y > 100) continue;
			y = ne[y];
			if (dist[y] == -1) {
				dist[y] = dist[f] + 1;
				que.push(y);
			}
		}
	}
	cout << dist[100] << endl;

}