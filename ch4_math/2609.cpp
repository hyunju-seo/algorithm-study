//#include <iostream>
//using namespace std;
//int gcd(int x, int y) {
//	if (y == 0) return x;
//	else return gcd(y, x % y);
//}
//int main() {
//	int a, b;
//	cin >> a >> b;
//	int g = gcd(a, b);
//	cout << g << '\n' << a * b / g << '\n';
//	return 0;
//}

#include<iostream>

using namespace std;
int main() {
	int A;
	int B;
	cin >> A;
	cin >> B;
	int g;
	int l;
	int a = A;
	int b = B;
	while (B != 0) {
		int r = A % B;
		A = B;
		B = r;
	}
	g = A;
	l = a * b / A;
	cout << g << endl;
	cout << l;