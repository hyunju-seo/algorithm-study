
#include<iostream>
#include<queue>
#include<cmath>

using namespace std;
vector<pair<int, int>> stars;
bool visited[101];

double distance(int x, int y, int x1, int y1) {
	return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
}
struct node {
	int nodeNum;
	double distance;
	bool operator < (const node &other)const {
		return distance > other.distance;
	}
};
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		stars.push_back({ x,y });
	}
	priority_queue<node> que;
	visited[0] = true;
	for (int i = 1; i < n; i++) {
		double dis = distance(stars[0].first, stars[0].second, stars[i].first, stars[i].second);
		que.push(node{i , dis });
	}
	double ans = 0;
	while (!que.empty()) {
		node f = que.top();
		//cout << f.nodeNum <<" " <<f.distance << endl;
		que.pop();
		if (visited[f.nodeNum]) continue;
		ans += f.distance;
		visited[f.nodeNum] = true;
		for (int i = 0; i < n; i++) {
			if (visited[i]) continue;
			double dis = distance(stars[f.nodeNum].first, stars[f.nodeNum].second, stars[i].first, stars[i].second);
			que.push(node{ i,dis });
			//cout << "que.push: " <<i << " " << dis << endl;
		}

	}

	printf("%.2f", ans);

	


}

