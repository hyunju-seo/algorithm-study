#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a[12][12];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		p[i] = i;
	}
	int ans = 0;
	bool start = true;
	do {
		bool con = true;

		int temp = 0;
		for (int i = 0; i < n-1; i++) {
		    int ret=a[p[i]][p[i+1]];
			if (ret == 0) {
				con = false;
				break; 
			}
			temp += ret;
		
		}
		if (con) {
			int ret = a[p[n - 1]][p[0]];
			if (ret == 0) continue;
			temp += ret;
			if (start) ans = temp;
			start = false;

			ans = min(temp, ans);
		}


	} while (next_permutation(p.begin(), p.end()));
	cout << ans << "\n";
}