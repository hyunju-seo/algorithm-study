//https://www.acmicpc.net/problem/10973

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (prev_permutation(a.begin(), a.end())==false) {
		cout<<-1;
	}
	else {
		for (auto e : a) {
			cout << e << " ";
		}
	}
	cout << "\n";
}