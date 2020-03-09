// top - down
#include<iostream>
#include<algorithm>
using namespace std;
int d[1000001];
int go(int n) {
	if (n ==1) {
		return 0;
	}
	if (d[n] > 0) {
		return d[n];
	}
	d[n] = go(n - 1) + 1;
	if (n % 3 == 0) {
		int ans =  go(n / 3) + 1;
		if (d[n] > ans) {
			d[n] = ans;
		}
	}
	if (n % 2 == 0) {
		int ans = go(n / 2) + 1;
		if (d[n] > ans) {
			d[n] = ans;
		}
	}
	return d[n];
}
	



int main() {
	int N;
	cin >> N;
	cout << go(N);
}
