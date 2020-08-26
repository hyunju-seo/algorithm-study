//https://www.acmicpc.net/problem/1707

#include<iostream>
#include<vector>

using namespace std;
vector<int> a[20001];
int group[20001];//0아직 방문x, 1group1, 2group2
void dfs(int node, int groupNum) {
	group[node] = groupNum;
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (group[next] == 0) {
			dfs(next, 3 - groupNum); //1 <-> 2
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t != 0) {
		t--;
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			a[i].clear();
			group[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		for (int i = 1; i <= n; i++) {
			if (group[i] == 0) {
				dfs(i, 1);
			}
		}
		bool ok = true;
		for (int i = 1; i <= n; i++) {
			for (int k = 0; i < a[i].size(); k++) {
				int j = a[i][k];
				if (group[i] == group[j]) ok = false;
			}
		}

		if (ok == false) cout << "NO";
		else cout << "YES";
	}
}
