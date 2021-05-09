#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	//vector<vector<int>>nums(n + 1, vector<int>(3));
	int nums[100001][3];
	int maxcache[2][3];
	int mincache[2][3];
	//vector<vector<int>>maxcache(2, vector<int>(3));
	//vector<vector<int>>mincache(2, vector<int>(3));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++)
			cin >> nums[i][j];
	}


	for (int j = 0; j < 3; j++) {
		maxcache[0][j] = nums[0][j];
		mincache[0][j] = nums[0][j];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			maxcache[1][j] = maxcache[0][j];
			mincache[1][j] = mincache[0][j];
			if (j + 1 < 3) {
				maxcache[1][j] = max(maxcache[0][j + 1], maxcache[1][j]);
				mincache[1][j] = min(mincache[0][j + 1], mincache[1][j]);
			}
			if (j - 1 >= 0) {
				maxcache[1][j] = max(maxcache[0][j - 1], maxcache[1][j]);
				mincache[1][j] = min(mincache[0][j - 1], mincache[1][j]);
			}


		}
		for (int j = 0; j < 3; j++) {
			maxcache[0][j] = maxcache[1][j] + nums[i][j];
			mincache[0][j] = mincache[1][j] + nums[i][j];
		}
	}
	int maxans = max({ maxcache[0][0],maxcache[0][1],maxcache[0][2] });
	int minans = min({ mincache[0][0],mincache[0][1],mincache[0][2] });
	cout << maxans << " " << minans << "\n";
}