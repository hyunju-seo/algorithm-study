#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int n;
vector<int> vec[100005];
vector<int> step(100005);
vector<int> answer;

void bfs(int start) {
	queue<int> que;
	que.push(start);
	step[start] = 1;
	while (!que.empty()) {
		int x = que.front();
		que.pop();
		for (auto v : vec[x]) {
			if (step[v] == 0) {
				step[v] = step[x] + 1;
				que.push(v);
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int from, to;
		cin >> from >> to;
		vec[from].push_back(to);
		vec[to].push_back(from);
	}
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		answer.push_back(a);
	}
	bfs(answer[0]);
	int ans = 1;
	queue<int> que;
	que.push(answer[0]);
	int p = -1;
	for (int i = 1; i < n; i++) {
		if (step[answer[i]] < step[answer[i - 1]]) ans = 0;
		if (step[answer[i]] == step[answer[i - 1]]) que.push(answer[i]);
		else {
			p = que.front();
			
			que.pop();
			for
		}
	}
	cout << ans << endl;
}