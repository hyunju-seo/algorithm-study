#include<iostream>
#include<algorithm>
int d[10001][2]; //1 i를 선택한 경우, 0 i를 선택하지 않은 경우
int a[10001];
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; 
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	d[1][1] = a[1];
	d[2][0] = a[1];
	d[2][1] = a[1] + a[2];
	for (int i = 3; i <= n; i++) {
		d[i][1] = max(d[i - 2][0]+a[i-1], d[i - 2][1])+a[i];
		d[i][0] = max(d[i - 1][0] ,d[i - 1][1]);
	}

	cout << max(d[n][0] , d[n][1])<<"\n";
}
//answer
//#include <iostream>
//using namespace std;
//int a[10001];
//int d[10001];
//int main() {
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; i++) {
//        cin >> a[i];
//    }
//    d[1] = a[1];
//    d[2] = a[1] + a[2];
//    for (int i = 3; i <= n; i++) {
//        d[i] = d[i - 1];
//        if (d[i] < d[i - 2] + a[i]) {
//            d[i] = d[i - 2] + a[i];
//        }
//        if (d[i] < d[i - 3] + a[i] + a[i - 1]) {
//            d[i] = d[i - 3] + a[i] + a[i - 1];
//        }
//    }
//    printf("%d\n", d[n]);
//    return 0;
//}