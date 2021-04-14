#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
struct Node {
	int from;
	int to;
	int cost;
};
long long inf = 100000000;
long long dist[501];
int main() {
	int n, m;
	cin >> n >> m;
	vector<Node> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i].from >> a[i].to >> a[i].cost;

	}
	for (int i = 1; i <= n; i++) {
		dist[i] = inf;
	}
	dist[1] = 0;
	bool negativeCycle = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			int from = a[j].from;
			int to = a[j].to;
			int cost = a[j].cost;

			if (dist[from] == inf) continue;
			if (dist[from] + cost < dist[to]) {
				dist[to] = dist[from] + cost;
				if (i == n )negativeCycle = true;
			}

		}
	}
	if (negativeCycle) cout << -1;
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == inf) cout << -1;
			else cout << dist[i];
			cout<< "\n";
		}
	}



}