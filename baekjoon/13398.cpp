#include<iostream>
#include<cstring>
using namespace std;
int seq[100001];
int rl[100001];
int lr[100001];
int n;
int left(int idx) {
	int& ret = lr[idx];
	if (idx == 0) {
		ret = seq[idx];
		return ret;
	}
	if (lr[idx] != -1) return ret;
	ret = max( seq[idx], left(idx - 1) +seq[idx]);

	return ret;
}

int right(int idx) {
	int& ret = rl[idx];
	if (idx == n - 1) {
		ret = seq[idx];
		return ret;
	}
	if (rl[idx] != -1) return ret;
	ret = max(seq[idx], right(idx + 1) + seq[idx]);

	return ret;
}

int main() {
	cin >> n;
	memset(rl, -1, sizeof(rl));
	memset(lr, -1, sizeof(lr));
	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}
	left(n - 1);
	right(0);
	
	
	int ans = lr[0];
	for (int i = 0; i < n; i++) {
		ans = max(ans, lr[i]);

	}
	for (int i = 1; i < n-1; i++) {
		ans = max(ans, lr[i - 1] + rl[i + 1]);
	}
	cout << ans;
}
