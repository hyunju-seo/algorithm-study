#include<iostream>
#include<algorithm>
#include<vector>
int d[2][1001];
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) {
		cin>>a[i];
	}

	for (int i = 1; i <= n; i++) {
		d[0][i] = 1;
		d[1][i] = 1;
		for (int j = 1; j < i; j++) {
			//증가하는 경우
			if (a[j] < a[i]) {
				d[0][i] = max(d[0][i], d[0][j] + 1);

			}
			//감소하는 경우
			else if (a[j] > a[i]) {
				d[1][i] = max({ d[1][i],d[1][j] + 1,d[0][j] + 1 });
			}
		}
	}
	int maximum = 0;
	for (int i = 1; i <= n; i++) {
		maximum = max({ maximum, d[0][i],d[1][i] });
	}
	cout << maximum<<"\n";
}