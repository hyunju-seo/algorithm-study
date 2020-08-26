#include <iostream>
#include<vector>
using namespace std;
//이렇게 하면 메모리 초과 => 256B( 정수 6000만개 정도)를 초과한다.
//d에 마지막 자리를 저장하지 말고, 계단 수를 저장하자.
vector<int> d1;
vector<int> d2;
int main() {
	d1 = { 1,2,3,4,5,6,7,8,9 };
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (i % 2 == 0) {
			d2.clear();
			for (auto e : d1) {
				if (e == 0) {
					d2.push_back(e + 1);
				}
				else if (e == 9) {
					d2.push_back(e - 1);

				}
				else {
					d2.push_back(e - 1);
					d2.push_back(e + 1);
				}
			}
		}
		else {
			d1.clear();
			for (auto e : d2) {
				if (e == 0) {
					d1.push_back(e + 1);
				}
				else if (e == 9) {
					d1.push_back(e - 1);

				}
				else {
					d1.push_back(e - 1);
					d1.push_back(e + 1);
				}

			}
		}
	}
	if (n % 2 == 0) {
		cout<<d2.size()% 1000000000;
	}
	else {
		cout << d1.size() % 1000000000;
	}
}