#include<iostream>
//틀
using namespace std;
int a[1001];
int main() {
	int n;
	cin >> n;
	a[1] = 1;
	a[2] = 2;
	for (int i = 3; i <= n; i++) {
		a[i] = a[i - 1] + a[i - 2]; ///이 경우 90 쯤에서 오버플로우 발생
	}
	
	cout << a[n] % 10007;

}