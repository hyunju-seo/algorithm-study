#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
struct Num {
	int idx;
	int val;
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, l;
	cin >> n >> l;
	vector<int> nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	deque<Num> que;
	int f = 0 - l + 1;
	int e = 0;
	que.push_front({ e, nums[e] });
	while (true) {
		cout << que.front().val << " ";
		if (f == que.front().idx) que.pop_front();
		f += 1;
		e += 1;
		if (e >= n) break;
		while (!que.empty()) {
			if (que.back().val <= nums[e]) break;
			que.pop_back();
		}
		que.push_back({ e, nums[e] });
	}
}