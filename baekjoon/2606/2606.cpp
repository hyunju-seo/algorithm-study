//https://www.acmicpc.net/problem/2606

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<int> nets[101];
int visited[101];
int main() {
	int n , m;
	cin >> n >>m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		nets[a].push_back(b);
		nets[b].push_back(a);

	}
	int ans =0;
	queue<int> que;
	que.push(1);
	visited[1] = true;
	while (!que.empty()) {
		int f = que.front();
		que.pop();
		for (auto t : nets[f]) {
			if (visited[t]) continue;
			que.push(t);
			visited[t] = true;
			ans += 1;
		}
	}
	cout << ans << "\n";

}