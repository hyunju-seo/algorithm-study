//10972
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (next_permutation(a.begin(), a.end()) == false) {
		cout << -1 << endl;
	}
	else {
		for (auto e : a) {
			cout << e << " ";
		}
	}
}