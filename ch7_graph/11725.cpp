//https://www.acmicpc.net/problem/11725
//endl 사용했더니 시간초과
#include<iostream>
#include<queue>

#include<vector>
using namespace std;
vector<int> tree[100005];
int n;
bool visited[100005];
int parent_num[100005];
void bfs(int root) {
	queue<int> que;
	que.push(root);
	visited[root] = true;
	while (!que.empty()) {
		int parent = que.front();
		que.pop();
		for (auto child : tree[parent]) {
			if (visited[child] == true) continue;
			visited[child] = true;
			parent_num[child] = parent;
			que.push(child);
		}
	}
}

int main() {

	cin >> n;
	for (int i = 1; i < n; i++) {
		int from, to;
		cin >> from >> to;
		tree[from].push_back(to);
		tree[to].push_back(from);

	}
	bfs(1);
	for (int i = 2; i <= n; i++) {
		cout << parent_num[i]<<"\n";
	}
}