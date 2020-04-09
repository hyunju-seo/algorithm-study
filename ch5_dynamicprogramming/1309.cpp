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


/*
//solution2
#include <iostream>
using namespace std;
int d[100001];
int s[100001];
int main() {
    int n;
    cin >> n;
    d[0] = 1;
    s[0] = 1;
    d[1] = 2;
    s[1] = d[0] + d[1];
    for (int i = 2; i <= n; i++) {
        d[i] = d[i - 1] + 2 * s[i - 2];
        s[i] = s[i - 1] + d[i];
        d[i] = d[i] % 9901;
        s[i] = s[i] % 9901;
    }
    cout << s[n] << '\n';
    return 0;
}

*/
