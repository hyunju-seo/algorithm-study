#include<iostream>

using namespace std;
bool check[1000001];
//false 소수
//true 소수 아님
int prime[1000001];
int pn;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 2; i < 1000001; i++) {
		if (check[i] == false) {
			prime[pn++] = i;
			int n=2;
			while (i * n < 1000001) {
				check[i * n] = true;
				n++;
			}
		}
	}

	int n;
	cin >> n;

	while (n != 0) {
		for (int i = 1; i < pn; i++) {  //prime[0]이 2니까 제외, 나머지는 모두 홀 수 
			if (check[n - prime[i]]==false) {
				cout << n << " = " << prime[i] << " + " << n - prime[i] << "\n";
				break;
			}
		
		}
		cin >> n;
	}
}