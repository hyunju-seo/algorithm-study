#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int indegree[32001];
vector<int> graph[32001];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int small, tall;
		cin >> small >> tall;
		graph[small].push_back(tall);
		indegree[tall] += 1;
	}
	queue<int> que;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) que.push(i);
	}

	while (!que.empty()) {
		int f = que.front();
		cout << f << " ";
		que.pop();
		for (auto g : graph[f]) {
			indegree[g] -= 1;
			if (indegree[g] == 0) {
				que.push(g);
			}
		}
	}

}

#include<iostream>
#include<vector>
using namespace std;
bool visited [32001];
vector<int> graph[32001];
void dfs(int x) {
	visited[x] = true;
	for (auto g : graph[x]) {
		if (visited[g]) continue;
		dfs(g);
	}
	cout << x << " ";
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int small, tall;
		cin >> small >> tall;
		graph[tall].push_back(small);
	}
	for (int i = 1; i <= n; i++) {
		if(!visited[i])
			dfs(i);
	}
}