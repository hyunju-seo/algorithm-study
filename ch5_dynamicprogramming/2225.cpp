//#include<iostream>
//long long d[201][201];   //d[k][n]
//using namespace std;
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	int n;
//	int k;
//	cin >> n;
//	cin >> k;
//	for (int i = 1; i <= k; i++) {
//		for (int j = 0; j <= n; j++) {
//			d[i][j] = 1LL;
//		}
//	}
//	for (int i = 2; i <= k; i++) {
//		for (int j = i; j <= n; j++) {
//			for (int p = 0; p < j; p++) {
//				d[i][j] += d[i - 1][p];
//			}
//		}
//	}
//	
//	
//	cout << d[k][n];
//}

#include <iostream>
using namespace std;
long long d[201][201];
long long mod = 1000000000;
int main() {
    int n, k;
    cin >> n >> k;
    d[0][0] = 1LL;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            for (int l = 0; l <= j; l++) {
                d[i][j] += d[i - 1][j - l];
                d[i][j] %= mod;
            }
        }
    }
    cout << d[k][n] << '\n';
    return 0;
}