#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	long long a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	if (a + b <= 2 * c) {
		cout << a * x + b * y << "\n";
	}
	else {
		cout << min(x, y) * 2 * c + (x - min(x, y)) * min(a,2*c) + (y - min(x, y)) * min(b, 2 * c) <<"\n";
	}
}