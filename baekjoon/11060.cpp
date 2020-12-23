#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int a[1002];
int cache[1002];
int func(int idx) {
	if (idx == 0) {
		cache[idx] = 0;
		return cache[idx];
	}
	if (cache[idx] != -1) return cache[idx];
	for (int i = 0; i < idx; i++) {
		if (i + a[i] >= idx) {
			int temp = func(i) + 1;
			if (cache[idx] == -1) cache[idx] = temp ;
			cache[idx] = min(cache[idx], temp);
		}
	}
	return cache[idx];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = func(n - 1);
	if (cache[0] ==-1) cout << -1;
	else cout << ans;

	//for (int i = 0; i < n; i++) {
	//	cout << cache[i] << " ";

	//}cout << endl;
	
}