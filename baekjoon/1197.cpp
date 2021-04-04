////프림
//#include<iostream>
//#include<vector>
//#include<queue>
//
//using namespace std;
//struct Edge {
//	int to;
//	int cost;
//	bool operator<(const Edge &other) const {
//		return cost > other.cost;
//	}
//};
//vector<Edge> info[10001];
//bool visited[10001];
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	int v, e;
//	cin >> v >> e;
//	
//	for (int i = 0; i < e; i++) {
//		int a, b, c;
//		cin >> a >> b >> c;
//		info[a].push_back(Edge{ b,c });
//		info[b].push_back(Edge{ a,c });
//
//	}
//	priority_queue<Edge> que;
//	visited[1] = true;
//	for (Edge e : info[1]) {
//		que.push(e);
//	}
//	int ans = 0;
//	while (!que.empty()) {
//		Edge e = que.top();
//		que.pop();
//		if (visited[e.to]) continue;
//		visited[e.to] = true;
//		ans += e.cost;
//		for (Edge ee : info[e.to]) {
//			que.push(ee);
//		}
//	}
//	cout << ans << "\n";
//}

//크루스칼
