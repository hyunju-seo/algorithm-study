// https://www.acmicpc.net/problem/15652

#include<iostream>
using namespace std;
int a[10];
void go(int index, int m, int n) {
	if (index == m ) {  //i�� �������� ���° �ڸ��� ������ ��Ÿ���Ƿ� m��° �ڸ��� �� �� �����ϱ� m�϶� ���
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