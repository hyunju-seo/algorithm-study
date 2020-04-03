#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> d(n+1);
	int x = 1;
	while (x*x <= n) {
		d[x * x] = 1;
		x++;
	}
	
	for (int i = 1; i <= n; i++) {
		if (d[i] == 0) {
			int mini = d[i-1]+1;
			for (int x = 2; x <= i / 2; x++) {
				mini = min(mini, d[x] + d[i - x]);
				if (mini == 2) break;
			}
			d[i] = mini;
		}
		
	}
	cout << d[n] << endl;
}