#include<iostream>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int lcd(int gcd, int a, int b) {
	return a * b / gcd;
}
int main() {

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int a;
		int b;
		cin >> a;
		cin >> b;
		int g = gcd(a, b);
		cout << lcd(g, a, b)<<"\n";
	}
}