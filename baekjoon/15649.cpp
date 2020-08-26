// https://www.acmicpc.net/problem/15649
/*
부르트포스 문제는 1. 재귀, 2. 순열, 3. 비트마스크로 풀 수 있다.
이 중 2와 3 번은 1번으로 풀 수 있다.
재귀를 사용하는 문제는 순서 문제, 선택 문제가 있다
*/
#include<iostream>
using namespace std;
bool c[10]; //수열에 i번째 수가 포함되어 있는지 여부
int a[10]; //수열을 저장함
void go(int index, int n, int m) { //index는 수열의 몇 번째 자리수인지 나타냄
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i];
			if (i != m - 1) {
				cout << " ";
			}
		}
		cout << "\n";
		return;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (c[i]) continue;
			else {
				c[i] = true;
				a[index] = i;
				go(index + 1, n, m);
				c[i] = false;
			}
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	go(0, n, m);

	
	
}