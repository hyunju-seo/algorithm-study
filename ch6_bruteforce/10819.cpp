//https://www.acmicpc.net/problem/10819

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> p(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		p[i]=a[i];

	}
	int ans = 0;

	do {
		int ans_1 = 0;
		for (int i = 0; i < n - 1; i++) {
			ans_1 += abs(p[i] - p[i + 1]);
		}
		ans = max(ans, ans_1);
	} while (prev_permutation(p.begin(), p.end()));

	do {
		int ans_1 = 0;
		for (int i = 0; i < n - 1; i++) {
			ans_1 += abs(a[i] - a[i + 1]);
		}
		ans = max(ans, ans_1);
	} while (next_permutation(a.begin(), a.end()));

	
	cout << ans<<"\n";
}