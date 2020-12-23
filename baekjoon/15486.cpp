#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int t[1500000];
int p[1500000];
int d[1500000 + 50];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];
	}
	for (int i = 0; i < n; i++) {
		d[i + t[i]] = max(d[i] + p[i], d[i + t[i]]);
		d[i + 1] = max(d[i], d[i + 1]);
	}
	cout << d[n];
}