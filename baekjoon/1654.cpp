#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int lan[10000];
int k, goalnum;

int calc(int l) {
	int ret = 0;
	for (int i = 0; i < k; i++) {
		ret += lan[i] / l;
	}
	return ret;
}
int main() {
	cin >> k >> goalnum;

	for (int i = 0; i < k; i++) {
		cin >> lan[i];
	}
	int start = 1;
	int end = *max_element(lan,lan+k);
	int ans = 0;
	if (calc(end) >= goalnum) { 
		cout << end << "\n"; return 0; 
	}
	while (start <= end) {
		int mid = (start + end) / 2;
		if (calc(mid) < goalnum) {//x
			end = mid - 1;
			//cout << "x" << endl;

		}
		else { //o
			start = mid + 1;
			ans = mid;
			//cout << "o" << endl;
		}
	}
	cout << ans << "\n";
}