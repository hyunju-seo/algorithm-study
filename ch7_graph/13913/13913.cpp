//https://www.acmicpc.net/problem/13913
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
bool check[100005];
int dist[100005];
int road[100005];
int n, k;
void printroad(int k) {
	if (k == -1) return;
	printroad(road[k]);
	cout << k << " ";
}
int main() {
	cin >> n >> k;
	queue<int> que;
	que.push(n);
	check[n] = true;
	dist[n] = 0;
	memset(road, -1, sizeof(road));
	while (!que.empty()) {
		int f = que.front();
		que.pop();
		if (f - 1 >= 0) {
			if (check[f - 1] == false) {
				check[f - 1] = true;
				dist[f - 1] = dist[f] + 1;
				road[f - 1] = f;
				que.push(f - 1);
			}
		}
		if (f + 1 <= 100000) {
			if (check[f + 1] == false) {
				check[f + 1] = true;
				dist[f + 1] = dist[f] + 1;
				road[f + 1] = f;

				que.push(f + 1);

			}
		}
		if (f * 2 <= 100000) {
			if (check[f * 2] == false) {
				check[f * 2] = true;
				dist[f * 2] = dist[f] + 1;
				road[f * 2] = f;

				que.push(f * 2);

			}
		}
		if (check[k] == true) {
			break;
		}
	}
	cout << dist[k] << endl;
	printroad(k) ;

}