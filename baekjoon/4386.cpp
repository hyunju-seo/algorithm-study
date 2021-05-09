#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
bool visited[101];
struct Node {
	int idx;
	double distance;
	bool operator<(const Node& other) const {
		return distance > other.distance;
	}
};

double distance(int x, int y, int x1, int y1) {
	double dis = (x - x1) * (x - x1) + (y - y1) * (y - y1);
	return sqrt(dis);
}

int main() {
	int n;
	cin >> n;
	vector<pair<double, double>> stars(n);
	for (int i = 0; i < n; i++) {
		cin >> stars[i].first >> stars[i].second;

	}
	visited[0] = true;
	priority_queue<Node> que;
	for (int i = 1; i < n; i++) {
		que.push({ i,distance(stars[0].first, stars[0].second, stars[i].first, stars[i].second) });
	}
	double ans = 0;
	while (!que.empty()) {
		Node q = que.top();
		que.pop();
		if (visited[q.idx])continue;
		visited[q.idx] = true;
		ans += q.distance;
		for (int i = 0; i < n; i++) {
			if (visited[i]) continue;
			que.push({ i, distance(stars[i].first, stars[i].second, stars[q.idx].first, stars[q.idx].second) });
		}
	}
	printf("%.2f", ans);

}