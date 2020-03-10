#include<iostream>
using namespace std;

int d[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	d[1] = 1;
	d[2] = 3;
	
	int n;
	cin >> n;

	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + 2*d[i - 2];
		d[i] %= 10007;
	}

	cout << d[n];

}