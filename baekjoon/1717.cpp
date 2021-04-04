#include<iostream>

using namespace std;
int parent[1000001];
int ranks[1000001];
int find(int c) {
	if (parent[c] == c) return c;
	int p= find(parent[c]);
	parent[c] = p;
	return p;
}
void merge(int a, int b) {
	int rootA = find(a);
	int rootB = find(b);
	if (rootA == rootB) return;
	if (ranks[rootA] < ranks[rootB]) swap(rootA, rootB);
	parent[rootB] = rootA;
	if (ranks[rootA] == ranks[rootB]) ranks[rootA] = ranks[rootB]+ 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
		ranks[i] = 1;
	}
	while (m != 0) {
		m -= 1;
		int temp, a, b;
		cin >> temp >> a >> b;
		if (temp == 0) {
			merge(a, b);
		}
		else {
			int rootA = find(a);
			int rootB = find(b);
			if (rootA == rootB) cout << "YES" << "\n";
			else cout << "NO" << "\n";
		}
	}
}