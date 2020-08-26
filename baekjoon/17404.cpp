#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//0 r, 1 g, 2 b
long long dr[3][1001];  //d[n][k] 마지막 집의 색깔이 n색 일 때, k번 째 집을 r색으로 짓는 최소 비용
long long dg[3][1001];
long long db[3][1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	vector<int> r(n + 1);
	vector<int> g(n + 1);
	vector<int> b(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> r[i] >> g[i] >> b[i];
	}
	dr[1][1] = dr[2][1] = r[1];
	dg[0][1] = dg[2][1] = g[1];
	db[0][1] = db[1][1] = b[1];
	dr[0][1] = dg[1][1] = db[2][1] = 1001;


	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= 2; j++) {	
			dr[j][i] = min(dg[j][i - 1], db[j][i - 1]) + r[i];

			dg[j][i] = min(dr[j][i - 1], db[j][i - 1]) + g[i];

			db[j][i] = min(dr[j][i - 1], dg[j][i - 1]) + b[i];

		}
	}

	dr[0][n] = min(db[0][n - 1], dg[0][n - 1])+r[n];
	dg[1][n] = min(dr[1][n - 1], db[1][n - 1])+g[n];
	db[2][n] = min(dg[2][n - 1], dr[2][n - 1])+b[n];

	cout << min({ dr[0][n], dg[1][n], db[2][n] });

}

//원형 문제를 풀 때 방법 : 직선인 경우를 풀고 그 후에 원형으로 바꿔준단