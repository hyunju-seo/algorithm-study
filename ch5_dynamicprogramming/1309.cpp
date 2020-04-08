#include<iostream>
using namespace std;
long long d[100001][4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	d[1][1] = 1;
	d[1][2] = 1;
	d[1][3] = 1;

	for (int i = 2; i < n+1; i++) {
		d[i][1] = ( d[i-1][2] + d[i - 1][3])% 9901;
		d[i][2] = (d[i - 1][1] + d[i - 1][2] + d[i - 1][3]) % 9901;
		d[i][3] = (d[i - 1][1] + d[i - 1][2]) % 9901;

	}
	cout<<(d[n][1]+d[n][2]+ d[n][3]) % 9901 <<"\n";



}