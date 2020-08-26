#include<iostream>
using namespace std;
long long d[1001][10];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int k = 0; k < 10; k++) {
		d[1][k] = 1;
	}

	for (int i = 2; i < n + 1; i++) {
		for (int k = 0; k < 10; k++) {
			for (int j = 0; j <= k; j++) {
				d[i][k] = (d[i - 1][j]+ d[i][k])% 10007;
			}
		}
	}
	long long answer = 0;
	for (int k = 0; k < 10; k++) {
		answer = (d[n][k]+answer)% 10007;
	}
	cout << answer<<"\n";


}