#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

vector<int> a[1001]; // 인접리스트
bool check[1001];
void dfs(int start) {
	stack<int>stk;
	stk.push(start);
	check[start] = true;
	cout << start << " ";
	while (!stk.empty()) {
		
		int node = stk.top();
		bool last = true;
		for (int i = 0; i < a[node].size(); i++) {
			int next = a[node][i];
			if (check[next] == false) {
				stk.push(next);
				check[next] = true;
				cout << next << " ";
				last = false;
				break;
			}
		}
		if (last == true) {
			stk.pop();
		}
	}
}

void bfs(int start) {

	fill_n(check, 1001, false);
	check[start] = true;
	queue<int> que;
	que.push(start);
	while (!que.empty()) {
		int node = que.front();
		que.pop();
		cout << node << " ";
		for (int i = 0; i < a[node].size(); i++) {
			int next = a[node][i];
			if (check[next] == false) {
				check[next] = true;
				que.push(next);

	
			}


		}

	}
}


int main() {
	int n, m, start;
	cin >> n >> m >> start;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());

	}
	dfs(start);
	cout << "\n";
	bfs(start);
	cout << "\n";

}