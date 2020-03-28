#include<iostream>
#include<vector>
using namespace std;
long long d1[100001] = { 1,0,1 };
long long d2[100001] = { 0,1,1 };
long long d3[100001] = { 0,0,1 };

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T != 0) {
		T--;
		int n;
		cin >> n;
		for (int i = 3; i < n; i++) {
			if (d1[i] + d2[i] + d3[i] == 0) {
				d1[i] = (d3[i - 1] + d2[i - 1]) % 1000000009;
				d2[i] = (d1[i - 2] + d3[i - 2]) % 1000000009;
				d3[i] = (d1[i - 3] + d2[i - 3]) % 1000000009;

			}
		}
		cout << (d1[n - 1] + d2[n - 1] + d3[n - 1]) % 1000000009 <<"\n";


	}

}