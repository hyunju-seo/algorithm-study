#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
bool visited[1001];
int minCost[1001];
int inf = 1000000000;
struct Node {
	int to;
	int cost;
	bool operator < (const Node &other) const {
		return cost > other.cost;
	}
};
vector<Node> city[1001];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		minCost[i] = inf;
	}
	for (int i = 0; i <m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		city[from].push_back({ to, cost });
	}
	int startNum, endNum;
	cin >> startNum>> endNum;
	visited[startNum] = true;
	minCost[startNum] = 0;
	priority_queue<Node> que;

	for (Node c : city[startNum]) {
		if (minCost[c.to] > minCost[startNum] + c.cost) {
			minCost[c.to] = c.cost + minCost[startNum];
			que.push({ c.to, minCost[c.to] });
		}
	}
	while (!que.empty()) {
		Node f = que.top();
		que.pop();
		if (visited[f.to]) continue;
		visited[f.to] = true;
		for (int i = 0; i < city[f.to].size(); i++) {
			Node next = city[f.to][i];
			if (visited[next.to]) continue;
			if (minCost[next.to] > minCost[f.to] + next.cost){
				minCost[next.to] = minCost[f.to] + next.cost;
				que.push({ next.to, minCost[next.to] });
			}
		}

	}

	cout << minCost[endNum] << "\n";
	

}