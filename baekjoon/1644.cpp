#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
bool complex[4000001];
int main() {
	int n;
	cin >> n;

	vector<int> prime;
	for (int i = 2; i <= n; i++) {
		if (!complex[i]) {
			prime.push_back(i);
			for (int j = i * 2; j <= n; j += i) complex[j] = true;
		}
	}
	int ans = 0;
	int f = 0;
	int e = 0;
	if (prime.empty()) cout << 0 << "\n";
	else {
		int sum = prime[e];
		int primesize = prime.size();
		//cout << primesize << endl;
		while (e < primesize && f <= e) {
			//cout << f << " " << e << endl;
			if (sum == n) {
				ans += 1;
				e += 1;
				if (e < primesize)	sum += prime[e];
			}
			else if (sum < n) {
				e += 1;

				if (e < primesize)	sum += prime[e];
			}
			else {
				sum -= prime[f];
				f += 1;
			}
			if (f > e && f < primesize) {
				f = e;
				sum = prime[e];
			}
		}cout << ans << "\n";
	}

}