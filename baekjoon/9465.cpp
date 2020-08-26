#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t != 0) {
		t--;
		int n;
		cin >> n;
		vector<int> d1(n);   //o
		                     //x
		vector<int> d2(n);   //x
		                     //o
		vector<int> d3(n);   //x
		                     //x
		vector<int> a1(n);
		vector<int> a2(n);

		for (int i = 0; i < n; i++) {
			cin >> a1[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> a2[i];
		}
		d1[0] = a1[0];
		d2[0] = a2[0];
		d3[0] = 0;

		for (int i = 1; i < n; i++) {
			d1[i] = max( d2[i - 1] ,d3[i - 1])+a1[i];
			d2[i] = max(d1[i - 1], d3[i - 1]) + a2[i];
			d3[i] = max({ d1[i - 1], d2[i - 1], d3[i - 1] });
		}
		cout << max({ d1[n - 1], d2[n - 1], d3[n - 1] }) << "\n";

	}
}