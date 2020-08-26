// https://www.acmicpc.net/problem/13023
#include<iostream>
#include<vector>
using namespace std;
bool a[2000][2000];  //�������, false
vector<int> g[2000]; //��������Ʈ
vector<pair<int, int>> edges; //��������Ʈ


int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from,to;
		cin >> from >> to;
		//�������
		a[from][to] = a[to][from]=true;

		//��������Ʈ
		g[from].push_back(to);
		g[to].push_back(from);

		//��������Ʈ
		edges.push_back({ from,to });
		edges.push_back({ to,from });

	}
	
	for (int i = 0; i < 2 * m; i++) {
		for (int j = 0; j < 2 * m; j++) {
			if (i == j) continue;
			int A = edges[i].first;
			int B = edges[i].second;
			int C = edges[j].first;
			int D = edges[j].second;

			if (A == B || A == C || A == D || B == C || B == D || C == D) continue;
			if (!a[B][C]) continue;

			for (auto e : g[D]) {
				if (e == A || e == B || e == C || e == D) continue;
				cout << 1 << "\n";
				return 0;
			}
		}
	}
	cout << 0 << "\n";
	return 0;

}