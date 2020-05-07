//https://www.acmicpc.net/problem/1707

#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;


int main() {
	int k;
	cin >> k;


	while (k != 0) {
		int group[20001] = {0};
		bool check[20001] = {0};
		vector<int> a[20001];

		k--;
		int v, e;
		cin >> v >> e;
		for (int i = 0; i < e; i++) {
			int from, to;
			cin >> from >> to;
			a[from].push_back(to);
			a[to].push_back(from);

		}

		bool ans = true;
		for (int i = 1; i <= v; i++) {
			if (check[i] == false) {
				queue<int> que;
				que.push(i);

				check[i] = true;
				group[i] = 1;

				while (!que.empty()) {
					int node = que.front();
					que.pop();
					for (int i = 0; i < a[node].size(); i++) {
						int next = a[node][i];

						if (check[next] == true) {
							if (group[next] != -group[node]) {
								ans= false;
							}
						}
						else {
							check[next] = true;
							que.push(next);
							group[next] = -group[node];
						}
					}
				}

			}
		}
		if (ans == false) cout << "NO" << "\n";
		else cout << "YES" << "\n";
	}

}