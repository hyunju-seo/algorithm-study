////kruskal
//#include<iostream>
//#include<queue>
//
//using namespace std;
//int parent[10001];
//int height[10001];
//struct Node {
//	int node1;
//	int node2;
//	int cost;
//	bool operator < (const Node& other) const {
//		return cost > other.cost;
//	}
//};
//
//int find(int c) {
//	if (parent[c] == c) return c;
//	int p = find(parent[c]);
//	parent[c] = p;
//	return p;
//}
//
//void merge(int a, int b) {
//	a = find(a);
//	b = find(b);
//	if (a == b) return;
//	if (height[a] < height[b]) swap(a, b);
//	parent[b] = a;
//	if (height[a] == height[b]) height[a] = height[b] + 1;
//}
//
//int main() {
//	int v, e;
//	cin >> v >> e;
//	for (int i = 1; i <= v; i++) {
//		parent[i] = i;
//		height[i] = 1;
//	}
//	priority_queue<Node> que;
//	for (int i = 0; i < e; i++) {
//		int a, b, c;
//		cin >> a >> b >> c;
//		que.push({ a, b, c });
//	}
//	int ans = 0;
//	while (!que.empty()) {
//		Node f = que.top();
//		que.pop();
//		int root1 = find(f.node1);
//		int root2 = find(f.node2);
//		if (root1 == root2) continue;
//	
//		ans += f.cost;
//		merge(f.node1, f.node2);
//	
//	}
//	cout << ans << "\n";
//}

//prim
#include<iostream>
#include<queue>
#include<vector>

using namespace std; 
struct Node {
	int node;
	int cost;
	bool operator < (const Node& other) const {
		return cost > other.cost;
	}
};
vector<Node> g[10001];
bool visited[10001];
int main() {
		int v, e;
		cin >> v >> e;
		for (int i = 0; i < e; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			g[a].push_back({ b,c });
			g[b].push_back({ a,c});
		}
		priority_queue<Node> que;
		visited[1] = true;
		for (auto n : g[1]) {
			que.push(n);
		}
		int ans = 0;
		while (!que.empty()) {
			auto f = que.top();
			que.pop();
			if (visited[f.node]) continue;
			
			ans += f.cost;
			visited[f.node] = true;
			for (auto n : g[f.node]) {
				if(!visited[n.node]) que.push(n);
			}
		}
		cout << ans << "\n";
}