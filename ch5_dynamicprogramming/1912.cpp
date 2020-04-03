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
	d[0] = a[0];
	int sum = a[0];
	
	for (int i = 1; i < n; i++) {
		if (a[i] > 0) {
			sum += a[i];
			d[i] = sum;

		}
		else {
			if (-a[i] > sum) {
				sum = 0;
				d[i] = a[i];
			}
			else {
				sum += a[i];
				d[i] = sum;

			}
		}
	}


	cout << *max_element(d.begin(), d.end())<<"\n";

}