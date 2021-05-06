#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	int b, c;
	cin >> b >> c;
	long long ret = 0;
	for (int i = 0; i < n; i++) {
		int a = A[i];
		//총감독관
		ret += 1;
		//부감독관
		if (a - b < 0) a = 0;
		else a -= b;
		ret += ( a/ c);
		if (a % c != 0) ret += 1;

	}cout << ret << "\n";
}