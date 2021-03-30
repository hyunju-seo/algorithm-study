#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
vector<int> questions[32001];
int indegree[32001];
bool visited[32001];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int p, l;
		cin >> p >> l;
		questions[p].push_back(l);
		indegree[l] += 1;
	}
	priority_queue<int, vector<int>, greater<int>> que;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) que.push(i);
	}

	while (!que.empty()) {
		int f = que.top();
		cout << f << " ";
		que.pop();
		for (int i = 0; i < questions[f].size(); i++) {
			int connectedNode = questions[f][i];
			if (visited[connectedNode]) continue;
			indegree[connectedNode] -= 1;
			if (indegree[connectedNode] == 0) {
				visited[connectedNode] = true;
				que.push(connectedNode);
			}
		
		}
	}
}