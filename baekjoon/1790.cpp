#include<iostream>
#include<string>
using namespace std;
long long calc(int num) {
	long long ans = 0;
	for (int len = 1, start = 1; start <= num; len++, start *= 10) {
		int end = start * 10 - 1;
		if (end > num) end = num;
		ans += (long long)(end - start + 1) * len;

	}
	return ans;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	if (calc(n) < k) {
		cout << -1 << '\n';
		return 0;
	}
	int left = 1;
	int right = n;
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		long long len = calc(mid);
		if (len < k) {
			left = mid + 1;
		}
		else {
			ans = mid;
			right = mid - 1;
		}
	}
	string s = to_string(ans);
	long long l = calc(ans);
	cout << s[s.length() - (l - k) - 1] << '\n';
	return 0;
}