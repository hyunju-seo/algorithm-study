#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int d[1001][3];

int main() {
	int n;
	cin >> n;
	vector<int> r(n+1);
	vector<int> g(n+1);
	vector<int> b(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> r[i] >> g[i] >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + r[i];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + g[i];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + b[i];

	}

	//int answer = d[n][0];
	//for (int i = 1; i < 3;i++) {
	//	answer = min(answer, d[n][i]);
	//}
	cout << min({ d[n][0],d[n][1],d[n][2] }) << endl;
	//cout << answer;

}