#include<iostream>
#include<queue>

using namespace std;
int dist[20001];
int from[20001];
int lastNum[20001];
void func(int h) {
	if (h == -1) return;
	int f = from[h];
	func(from[h]);
	cout << lastNum[h];
}
int main() {
	int t;
	cin >> t;
	while (t != 0) {
		t -= 1;
		int n;
		cin >> n;
		for (int i = 0; i <= n; i++) {
			dist[i] = -1;
			from[i] = -1;
			lastNum[i] = -1;
		}
		queue<int> que;
		dist[1%n] = 0;
		lastNum[1 % n] = 1;
		que.push(1 % n);
		while (!que.empty()) {
			int f= que.front();
			que.pop();
			for (int i = 0; i <= 1; i++) {
				int next = (f * 10 + i) % n;
				if (dist[next] == -1) {
					dist[next] = dist[f] + 1;
					from[next] = f;
					lastNum[next] = i;
					que.push(next);
				}
			}
			if (dist[0] != -1) break;

		}

		if (dist[0] == -1) cout << "BRAK" << "\n";
		else {
			func(0);
			cout << "\n";
		}

	}
}