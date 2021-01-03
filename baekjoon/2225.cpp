#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long mod = 1000000000;
int n, k;
long long d[201][201];
long long func(int i, int j) {
	//cout << i << " " << j << endl;
	if (j == 1) {
		d[i][j] = j;
		return d[i][j];
	}
	if (d[i][j] != -1) 	return d[i][j];
	d[i][j] = 0;
	for (int id = 0; id <= i; id++) {
	//if (n - id <= id) continue;
		d[i][j] += func(id, j-1);
	}
	d[i][j] %= mod;
	return d[i][j];

}

int main() {
	cin >> n >> k;
	memset(d, -1, sizeof(d));
	cout << func(n, k);
}