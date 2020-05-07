//https://www.acmicpc.net/problem/11724

#include<iostream>
#include<queue>

using namespace std;
bool check[1001];
vector<int> a[1001];
void bfs(int start) {
	queue<int> que;
	que.push(start);
	check[start];
	while (!que.empty()) {
		int node = que.front();
		que.pop();
		for (int i = 0; i < a[node].size(); i++) {
			int next = a[node][i];
			if (check[next] == false) {
				check[next] = true;
				que.push(next);
			}
		}
	}
}

//int min_index(int n) {
//	for (int i =1; i <= n; i++) {
//		if (check[i] == false) return i;
//	}
//	return 0;
//}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			bfs(i);
			answer += 1;
		}
	}
	//시간 초과
	//while (true) {
	//	int start = min_index(n);
	//	if (start == 0) {
	//		break;
	//	}
	//	answer += 1;
	//	bfs(start);
	//}
	cout << answer << "\n";

}