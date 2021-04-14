#include<iostream>
#include<queue>

using namespace std;

int parent[1001];
int height[1001];

struct Node {
	int node1;
	int node2;
	int cost;
	bool operator < (const Node& other) const {
		return cost > other.cost;

	}

};

int find(int c) {
	if (c == parent[c]) return c;
	int root= find(parent[c]);
	parent[c] = root;
	return root;
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (height[a] > height[b]) swap(a, b); // a가 항상 작도록
	parent[a] = b;
	if (height[a] == height[b]) height[b] = height[a] + 1;
}


int main() {

	int n, m;
	cin >> n >> m;
	priority_queue<Node> que;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		que.push(Node{ a,b,c });

	}
	int ans = 0;
	while (!que.empty()) {
		Node f = que.top();
		que.pop();
		if (find(f.node1) == find(f.node2)) continue;
		ans += f.cost;
		merge(f.node1, f.node2);

	}
	cout << ans << "\n";
}