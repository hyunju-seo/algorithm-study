#include<iostream>
#include<vector> 
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> a(n);
	vector<vector<int>> d(n);
	for (int i = 0; i < n; i++) {
		vector<int> in(i+1);
		a[i] = in;
		d[i] = in;
	}


	for (int i = 0; i < n; i++) {
		for (int j=0; j <= i; j++) {
			cin>>a[i][j];
		}
	}
	d[0][0] = a[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			//왼쪽 가장자리
			if (j == 0) {
				d[i][j] = d[i - 1][j] + a[i][j];
			}
			//오른쪽 가장자리
			else if (j == i) {
				d[i][j] = d[i - 1][j - 1] + a[i][j];
			}
			else {
				d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + a[i][j];
			}
		}
	}


	cout << *max_element(d[n-1].begin(), d[n - 1].end())<<"\n";
}