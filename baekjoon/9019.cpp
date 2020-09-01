#include<iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <string>
#include <stack>

using namespace std;
int dist[10002];
int how[10002];
char ch[10002];
int from, to;

int d(int n) {
	return 2 * n % 10000;
}
int s(int n) {
	if (n == 0) return 9999;
	return n - 1;
}
int l(int n) {
	//1234 - 2341
	int a = n / 1000;
	int b = n % 1000;
	return b * 10 + a;
}
int r(int n) {
	//1234-4123
	int a = n / 10;
	int b = n % 10;
	return b * 1000 + a;

}
void findans(int n) {
	if (n == from) {
		return;
	}
	findans(how[n]);
	cout << ch[n];
}
string str = "DSLR";
int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		memset(dist, -1, sizeof(dist));
		
		cin >> from >> to;
		dist[from] = 0;
		queue<int> que;
		que.push(from);
		how[from] = -1;
		bool done = false;
		while (!que.empty()) {
			int f = que.front();
			que.pop();

			vector<int> arr;
			arr.push_back(d(f));
			arr.push_back(s(f));
			arr.push_back(l(f));
			arr.push_back(r(f));
			for (int i = 0; i < 4; i++) {
				int ftemp = arr[i];
				if (dist[ftemp] != -1) continue;
				dist[ftemp] = dist[f] + 1;
				how[ftemp] = f;
				ch[ftemp] = str[i];
				if (ftemp == to) {
					done = true;
					break;

				}
				que.push(ftemp);
			}
			if (done) break;


		}
		findans(to);
		cout << "\n";
	}

}