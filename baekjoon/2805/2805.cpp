#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long cutTree(long long cutter, vector<long long> treeHeight) {
	long long ret = 0;
	for (auto t : treeHeight) {
		if (t <= cutter) continue;
		ret += (t - cutter);
	}
	return ret;
}

int main() {
	long long n, m;
	cin >> n >> m;
	vector<long long> treeHeight(n);
	long long minlen, maxlen;
	cin >> treeHeight[0];
	minlen = 0;
	maxlen = treeHeight[0];
	for (int i = 1; i < n; i++) {
		cin >> treeHeight[i];
		maxlen = max(treeHeight[i], maxlen);
	}
	long long cutter;
	long long answer=minlen;
	while (true) {
		if (minlen > maxlen) break; // 이 조건이 있어야 무한루프에 안빠짐
		cutter = (minlen + maxlen) / 2;

		long long takeHome = cutTree(cutter, treeHeight);
		if (takeHome == m) {
			answer = max(cutter, answer);  
			break; 
		}
		if (takeHome > m) {
			answer = max(cutter, answer);
			minlen = cutter + 1;
		}
		else 
			maxlen = cutter - 1;		
	}

	cout << answer;
}
//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//#include <vector>
//#include <algorithm>
//using namespace std;
//bool check(vector<long long>& a, long long mid, long long m) {
//    int n = a.size();
//    long long cnt = 0;
//    for (int i = 0; i < n; i++) {
//        if (a[i] - mid > 0) {
//            cnt += a[i] - mid;
//        }
//    }
//    return cnt >= m;
//}
//int main() {
//    int n;
//    long long m;
//    scanf("%d %lld", &n, &m);
//    vector<long long>a(n);
//    long long l = 0;
//    long long r = 0;
//    for (int i = 0; i < n; i++) {
//        scanf("%lld", &a[i]);
//        if (r < a[i]) {
//            r = a[i];
//        }
//    }
//    long long ans = 0;
//    while (l <= r) {
//        long long mid = (l + r) / 2;
//        if (check(a, mid, m)) {
//            ans = max(ans, mid);
//            l = mid + 1;
//        }
//        else {
//            r = mid - 1;
//        }
//    }
//    printf("%lld\n", ans);
//    return 0;
//}