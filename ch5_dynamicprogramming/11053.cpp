#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	vector<int> d(N);
	for (int i = 0; i < N;i++) {
		int A;
		cin >> A;
		a[i] = A;
	}

	for (int i = 0; i < N; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i]&&d[i]<d[j]+1) {
				d[i] = d[j] + 1;
			}
		}
	}

	cout << *max_element(d.begin(), d.end());

}