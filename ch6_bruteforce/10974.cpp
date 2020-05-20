#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i < n + 1;i++) {
		a[i] = i;
	}
	while (true) {
		for (int i = 1; i < n + 1; i++) {
			cout << a[i]<<" ";
		}
		cout << "\n";
		if (next_permutation(a.begin() + 1, a.end()) == false) break;
	}
}