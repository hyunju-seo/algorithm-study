#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int a[100001];
int main() {
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int f = 0;
	int e = 0;
	int sum = a[e];
	int ans = 1000001;
	while (e < n) {
		if (sum >= s) {
			//cout << f << "  " << e << endl;
			ans = min(ans, e - f + 1);
			sum -= a[f];
			f += 1;
		}
		else if (sum < s) {
			e += 1;
			sum += a[e];
		}

		if (f > e) {
			e = f;
			sum = a[f];
		}
	}
	if (ans == 1000001) cout << 0 << "\n";
	else cout << ans << "\n";

}