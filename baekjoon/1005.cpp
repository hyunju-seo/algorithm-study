#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
vector<int> graph[1001];
int times[1001];
int visited[1001];
int dfs(int node) {
	int len = graph[node].size();
	int ret = 0;
	for (int i = 0; i < len; i++) {
		if (visited[graph[node][i]] != -1) {
			ret = max(ret, visited[graph[node][i]]);
		}
		else  ret = max(ret, dfs(graph[node][i]));
	}
	visited[node] = times[node] + ret;
	return times[node] + ret;
}


int main() {
	int t;
	cin >> t;
	while (t != 0) {

		t -= 1;
		int n, k;
		cin >> n >> k;
		for (int i = 0; i <= n; i++) {
			graph[i].clear();
			visited[i] = -1;
		}

		for (int i = 1; i <= n; i++) {
			cin >> times[i];
		}
		for (int i = 0; i < k; i++) {
			int from, to;
			cin >> from >> to;
			graph[to].push_back(from);
		}
		int goal;
		cin >> goal;
		cout << dfs(goal) << "\n";