#include<iostream>
using namespace std;

int d[12];

int main() {
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		for (int k = 4; k <= n; k++) {
			d[k] = d[k - 1] + d[k - 2] + d[k - 3];
		}
		cout << d[n];
	}
}