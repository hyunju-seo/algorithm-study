#include<iostream>

using namespace std;

int power(int n) {
	return 1 << n;
}

int func(int x, int y, int n) {
	if (n == 1) {
		return 2*x+y;
	}

	if (x < power(n - 1)) {
		//1사분면
		if (y < power(n - 1)) {
			//cout << "1" << endl;

			return func(x, y, n - 1);
		}

		//2사분면
		else {
			//cout << "2" << endl;

			return func(x, y - power(n - 1), n - 1) + power(2 * n - 2);
		}

	}
	else {
		if (y < power(n - 1)) {
			//cout << "3" << endl;
			//3
			return func(x - power(n - 1), y, n - 1) + power(2 * n - 2) * 2;
		}

		else {
			//cout << "4" << endl;

			//4
			return func(x - power(n - 1), y - power(n - 1), n - 1) + power(2 * n - 2) * 3;
		}

	}

}

int main() {
	int n, r, c;
	cin >> n >> r >> c;
	cout << func(r, c, n);
}