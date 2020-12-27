//#include<iostream>
//#include<algorithm>
////틀린이유: 반례 31253  같은 수가 중복될 경우
//using namespace std;
//int a[500003];
//int asort[500003];
//int aidx[1000001];
//int main() {
//	int N;
//	cin >> N;
//	for (int i = 0; i < N ; i++) {
//		cin >> a[i];
//		aidx[a[i]] = i;
//		asort[i] = a[i];
//	}
//	sort(asort, asort + N);
//	int maxi = 0;
//
//	for (int i = 0; i < N; i++) {
//		if (aidx[asort[i]] <= i) continue;
//		int temp = aidx[asort[i]] - i;
//		maxi = max(temp, maxi);
//	}
//	cout << maxi + 1 << "\n";
//}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> arr;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr.push_back({ temp,i });
	}
	sort(arr.begin(), arr.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, arr[i].second - i);
	}
	cout << ans + 1 << "\n";

}