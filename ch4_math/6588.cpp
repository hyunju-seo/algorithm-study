#include<iostream>

using namespace std;

bool check[1000001];
//false 소수임 
// true 소수 아님

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	check[1] = true;
	for (int i = 2; i*i < 1000001; i++) {
		if (check[i] == false) {
			int n = 2;
			while (i * n < 1000001) {
				check[i * n] = true;
				n++;
			}
		}
	}
	
	int n;
	cin >> n;
	while (n != 0) {
		int a = 0;
		for ( a = 3; a < n; a += 2) {
			int b = n - a;
			if (check[a]==false &&check[b] == false) {
				cout << n << " = " << a << " + " << b << "\n";
				break;
			}
		}
		if (a > n) {
			cout << "Goldbach's conjecture is wrong." << "\n";
		}
		cin >> n;
	}
}