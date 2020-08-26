#include<iostream>
#include<algorithm>

using namespace std;

int inp[500002];
int n, m;

int lowerbound(int num) {
	int ret=-1;
	int l = 0;
	int r = n-1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (inp[mid] == num) {
			ret = mid;
			r = mid - 1;
		}
		else if (inp[mid] < num) {
			l = mid + 1;
		}
		else {
			r = mid - 1;

		}
	}
	return ret;
}
int upperbound(int num) {
	int ret = -1;
	int l = 0;
	int r = n - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (inp[mid] == num) {
			ret = mid+1;
			l = mid + 1;
		}
		else if (inp[mid] < num) {
			l = mid + 1;
		}
		else {
			r = mid - 1;

		}
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> inp[i];
	}
	sort(inp, inp + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int in;
		cin >> in;
		auto p = equal_range(inp, inp + n, in);
		cout << p.second - p.first << " ";
		//cout << upperbound(in) - lowerbound(in)<<" ";
	}
	cout << "\n";
}