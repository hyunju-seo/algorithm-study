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
long long d[201][201];   //d[k][n] k개를 더해서 합이 n이 되는 경우의 수
long long mod = 1000000000;
int main() {
    int n, k;
    cin >> n >> k;
    d[0][0] = 1LL;
//d[k][n]=sum(d[k-1][n-l]
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

/*//sol2
#include <iostream>
using namespace std;
long long d[201][201];
long long mod = 1000000000;
int main() {
    int n, k;
    cin >> n >> k;
    d[0][0] = 1LL;
    for (int i=1; i<=k; i++) {
        for (int j=0; j<=n; j++) {
            d[i][j] = d[i-1][j];
            if (j-1 >= 0) {
                d[i][j] += d[i][j-1];
            }
            d[i][j] %= mod;
        }
    }
    cout << d[k][n] << '\n';
    return 0;
}*/

/*
//sol3 합분해 문제에서만 적용할 수 있는 방법
#include <iostream>
using namespace std;
long long d[201];
const long long mod = 1000000000;
int main() {
    int n, m;
    cin >> n >> m;
    d[0] = 1;
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            d[j] += d[j-1];
            d[j] %= mod;
        }
    }
    cout << d[n] << '\n';
    return 0;
}
*/