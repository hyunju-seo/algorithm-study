#include<iostream>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t != 0) {
		t--;
		long long n, m;
		cin >> n >> m;
		long long season = n / 5;
		long long normal = m / 7;
		if (season <= normal) cout << season << "\n";
		else {
			long long answer = normal;
			n = n - normal * 5;
			m = m % 7;
			answer += (m + n) / 12;

			cout << answer << "\n";

		}
	}
	return 0;
}