#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> d(n);    //d[i]로 끝나는 가장 긴 증가하는 부분 수열
    vector<int> d2(n);   //d[i]에서 시작하는 가장 긴 감소하는 부분 수열
    //가장 긴 증가하는 부분 수열
    for (int i = 0; i < n; i++) {
        d[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && d[j] + 1 > d[i]) {
                d[i] = d[j] + 1;
            }
        }
    }
    //가장 긴 감소하는 부분수열
    for (int i = n - 1; i >= 0; i--) {
        d2[i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j] && d2[j] + 1 > d2[i]) {
                d2[i] = d2[j] + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (ans < d[i] + d2[i] - 1) {
            ans = d[i] + d2[i] - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}