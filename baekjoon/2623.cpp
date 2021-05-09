#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<int> graph[1001];
int indegree[1001];
int main() {
	int singer, pd;
	cin >> singer >> pd;
	for (int i = 0; i < pd; i++) {
		int n;
		cin >> n;
		vector<int> temp(n);
		for (int j = 0; j < n; j++) {
			cin >> temp[j];
		}
		for (int j = 0; j < n - 1; j++) {
			int from = temp[j];
			int to = temp[j + 1];
			graph[from].push_back(to);
			indegree[to] += 1;
		}
	}
	queue<int> que;
	for (int i = 1; i <= singer; i++) {
		if (indegree[i] == 0) {
			que.push(i);
		}
	}
	vector<int> orders;
	while (!que.empty()) {
		int f = que.front();
		que.pop();
		orders.push_back(f);
		int fsize = graph[f].size();
		for (int i = 0; i < fsize; i++) {
			indegree[graph[f][i]] -= 1;
			if (indegree[graph[f][i]] == 0) que.push(graph[f][i]);
		}

	}
	if (orders.size() < singer) cout << 0 << "\n";
	else {
		for (auto o : orders) cout << o << "\n";
	}




}