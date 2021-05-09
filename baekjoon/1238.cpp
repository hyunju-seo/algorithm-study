#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Node {
	int idx;
	int time;
	bool operator< (const Node& other) const {
		return time > other.time;
	}
};
bool visited[1001];
bool invisited[1001];
vector<Node> graph[1001];
vector<Node> ingraph[1001];
int dist[1001];
int indist[1001];
const int INF = 1000000000;

int main() {
	int n, m, x;
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int from, to, t;
		cin >> from >> to >> t;

		graph[from].push_back({ to, t });

		ingraph[to].push_back({ from, t });
	}
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
		indist[i] = INF;
	}
	dist[x] = 0;
	priority_queue<Node> que;

	que.push({ x,dist[x] });

	while (!que.empty()) {
		Node n = que.top();
		que.pop();
		if (visited[n.idx]) continue;
		visited[n.idx] = true;
		for (Node no : graph[n.idx]) {
			if (dist[no.idx] > no.time + dist[n.idx]) {
				dist[no.idx] = no.time + dist[n.idx];
				que.push({ no.idx, dist[no.idx] });
			}

		}
	}
	indist[x] = 0;
	priority_queue<Node> inque;

	inque.push({ x,dist[x] });

	while (!inque.empty()) {
		Node n = inque.top();
		inque.pop();
		if (invisited[n.idx]) continue;
		invisited[n.idx] = true;
		for (Node no : ingraph[n.idx]) {
			if (indist[no.idx] > no.time + indist[n.idx]) {
				indist[no.idx] = no.time + indist[n.idx];
				inque.push({ no.idx, indist[no.idx] });

			}
		}
	}
	int ans = -1;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dist[i] + indist[i]);
	}cout << ans << endl;
}