#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

vector<int> vec[1001];
bool visited[1001];
int main() {
	int tc;
	cin >> tc;
	while (tc != 0) {
		tc -= 1;
		memset(visited, false, sizeof(visited));

		int n, m;
		cin >> n >> m;

		for (int i = 0; i <= n; i++) vec[i].clear();
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		queue<int> que;
		que.push(1);
		visited[1] = true;
		int ans = 0;
		while (!que.empty()) {
			int f = que.front();
			que.pop();
			auto temp = vec[f];
			for (auto te : temp) {
				if (visited[te]) continue;
				que.push(te);
				visited[te] = true;
				ans += 1;
			}
		}
		cout << ans<<"\n";

	}
}