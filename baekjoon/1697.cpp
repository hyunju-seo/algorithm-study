#include<iostream>
#include<queue>
using namespace std;
bool check[100005];
int dist[100005];
int n, k;
int main() {
	cin >> n >> k;
	queue<int> que;
	que.push(n);
	check[n] = true;
	dist[n] = 0;
	while (!que.empty()) {
		int f = que.front();
		que.pop();
		if (f - 1 >= 0) {
			if (check[f-1] == false) {
				check[f-1] = true;
				dist[f - 1] = dist[f] + 1;
				que.push(f - 1);
			}
		}
		if (f + 1 <= 100000) {
			if (check[f + 1] == false) {
				check[f + 1] = true;
				dist[f + 1] = dist[f] + 1;
				que.push(f + 1);

			}
		}		
		if (f *2 <= 100000) {
			if (check[f * 2] == false) {
				check[f * 2] = true;
				dist[f * 2] = dist[f] + 1;
				que.push(f * 2);

			}
		}
		if (check[k] == true) {
			break;
		}
	}
	cout << dist[k] << endl;
}