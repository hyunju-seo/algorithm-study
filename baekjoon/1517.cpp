#include<iostream>
#include<vector>
//자기보다 앞에있는 수 중 큰수의 개수를 구해라
using namespace std;
vector<long long> nums;
long long b[500001];
long long ans = 0;
void msort(int s, int e, int m) {
	//cout << "msort " << s << " " << e << endl;

	int f = s;
	int l = m+1;
	int idx = s;
	while (f <= m &&l<=e) {
		if (nums[f] <= nums[l]) {
			b[idx++] = nums[f++];
		}
		else {
			b[idx++] = nums[l++];
			ans += m - f+1;
		//	cout << "ans " << ans << endl;
		}
	}
	while (f <= m) {
		b[idx++] = nums[f++];
	}
	while (l <= e) {
		b[idx++] = nums[l++];
	}
	for (int i = s; i <= e; i++) {
		nums[i] = b[i];
	}
}

void func(int s, int e) {
	//cout << "func " << s << " " << e << endl;
	if (s == e) return;
	int m = (s + e) / 2;
	func(s, m);
	func(m+1, e);
	msort(s, e,m);
}

int main() {
	int n;
	cin >> n;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		nums.push_back(temp);
	}
	func(0, n-1);
	//for (auto t : nums) {
	//	cout << t << " ";
	//}

	cout << ans << "\n";
}
