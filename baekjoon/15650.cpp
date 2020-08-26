#include<iostream>
using namespace std;
int sequence[10];
//bool c[10];
void go(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << sequence[i];
			if (i != m - 1) {
				cout << " ";
			}
		}
		cout << "\n";
		return;
	}
	else {
		for (int i = 1; i <= n; i++) {			
			if (sequence[index-1]<i) {

			//if (c[i] == false  && sequence[index-1]<i) {
				//c[i] = true;
				sequence[index] = i;
				go(index + 1, n, m);
				//c[i] = false;
			}
		}
	}
}



int main() {
	int n, m;
	cin >> n >> m;
	go(0, n, m);
}