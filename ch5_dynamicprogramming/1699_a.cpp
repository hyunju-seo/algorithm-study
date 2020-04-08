#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> d(n+1);
	d[1] = 1;
	for (int i = 2; i <= n; i++) {
		d[i] = i;
		for (int j = 1; j*j <= i;j++) {
			d[i] = min(d[i - j * j] + 1,d[i]);
		}
	}
	cout << d[n];
}