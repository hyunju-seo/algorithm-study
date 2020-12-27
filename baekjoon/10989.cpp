#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	while(n!=0) {
		n -= 1;
		int temp;
		cin >> temp;
		a[temp] += 1;
	}
	for (int i = 0; i < 10001; i++) {
		if (a[i] == 0)  continue;
		while (a[i] != 0) {
			cout << i << "\n";
			a[i] -= 1;
		}
	}

}