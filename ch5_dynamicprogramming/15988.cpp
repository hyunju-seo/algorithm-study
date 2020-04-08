#include<iostream>

using namespace std;
long long d[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	int i = t;
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	while (i != 0) {
		i--;
		int n;
		cin >> n;
		for (int j = 4; j <= n; j++) {
			d[j] = (d[j - 1] + d[j - 2] + d[j - 3])% 1000000009;
		}
		cout << d[n]<<"\n";
	}
	
	
}