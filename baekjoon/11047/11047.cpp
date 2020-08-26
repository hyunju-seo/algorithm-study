#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> cvalue;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		cvalue.push_back(c);
	}
	int ans = 0;
	for (int i = cvalue.size()-1; i >= 0; i--) {
		int v = cvalue[i];
		if (k < v) continue;
		ans += k / v;
		k = k % v;

	}
	cout << ans << "\n";
}