#include<iostream>
using namespace std;
//d[계단 길이][마지막 수]=>개수
long long d[100][10];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= 9; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i <=n  ; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j > 0) {
				d[i][j] += d[i - 1][j - 1];

			}
			if (j < 9) {
				d[i][j] += d[i - 1][j + 1];
			}
			d[i][j] %= 1000000000;  //답에 mod 있는 문제는 계속 나눠주기!

		}
		
	
	}
	long long ans = 0;
	for (int i = 0; i < 10;i++) {
		ans += d[n][i];
	}

	cout << ans % 1000000000;
}