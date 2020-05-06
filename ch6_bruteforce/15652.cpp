// https://www.acmicpc.net/problem/15652

#include<iostream>
using namespace std;
int a[10];
void go(int index, int m, int n) {
	if (index == m ) {  //i는 수열에서 몇번째 자릿수 인지를 나타내므로 m번째 자릿수 일 수 없으니까 m일때 출력
		for (int i = 0; i < m; i++) {
			cout << a[i];
			if (i != m-1 ) {
				cout << " ";
			}
		}
		cout << "\n";
		return;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (index!=0&&a[index-1]>i) {
				continue;
			}
			a[index] = i;
		
			go(index + 1, m, n);
		}
	}
}

int main() {
	int m, n;
	cin >> n >> m;
	go(0, m, n);
}