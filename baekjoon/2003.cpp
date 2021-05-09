#include<iostream>
#include<vector>
using namespace std;
//int a[10001];
int main() {

	int n, m;
	cin >> n >> m;
	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int s = 0;
	int e = 0;
	int sum = a[0];
	int ans = 0;
	while (e < n) {
		if (sum == m) {
			ans += 1;
			sum -= a[s];
			e += 1; s += 1;
			sum += a[e];

		}
		else if (sum > m) {
			sum -= a[s];
			s += 1;
		}
		else {
			e += 1;
			sum += a[e];
		}
	}
	cout << ans;
}