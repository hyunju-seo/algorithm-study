// https://www.acmicpc.net/problem/15649
/*
�θ�Ʈ���� ������ 1. ���, 2. ����, 3. ��Ʈ����ũ�� Ǯ �� �ִ�.
�� �� 2�� 3 ���� 1������ Ǯ �� �ִ�.
��͸� ����ϴ� ������ ���� ����, ���� ������ �ִ�
*/
#include<iostream>
using namespace std;
bool c[10]; //������ i��° ���� ���ԵǾ� �ִ��� ����
int a[10]; //������ ������
void go(int index, int n, int m) { //index�� ������ �� ��° �ڸ������� ��Ÿ��
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