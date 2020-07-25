//https://www.acmicpc.net/problem/1182
#include<iostream>

using namespace std;
int n, s;

int arr[40];
int ans=0;
void parray(int sum, int idx) {
	//cout << "parray(sum: " << sum << " ,idx: " << idx << ")" << endl;
	if (idx == n) return;
	if (sum+arr[idx] == s) ans++;
	
	parray(sum + arr[idx], idx+1);
	parray(sum, idx + 1);
}
int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	parray(0, 0);
	cout << ans<<"\n";
}