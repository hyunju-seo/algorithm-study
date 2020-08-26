#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	d[0] = a[0];  //continueµµ »ç¿ë
	for (int i = 1; i < n; i++) {
		d[i] = max(a[i], d[i - 1] + a[i]);
	}
	cout << *max_element(d.begin(), d.end())<<endl;
}