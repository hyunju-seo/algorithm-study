#include<iostream>
int a[10];
using namespace std;

//�ڿ��� index�� ������ ���� �Ǵ��� �ȵǴ����� ���ϴ� �Լ�
void go(int index, int selected, int n, int m) {    //selected : ������ ��� �ִ���
	if (selected == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i]<<" ";

		}
		cout << endl;
		return;
	}
	if (index > n) return;
	a[selected] = index;
	go(index + 1, selected + 1, n,m);
	a[selected] = 0;
	go(index + 1, selected, n, m);
}

int main() {
	int n, m;
	cin >> n >> m;
	int selected=0;

	go(1, 0, n, m);

	/*
	15650.cpp�� �ð� ���⵵�� n!������ 
	�� Ǯ�� ����� �ð� ���⵵�� 2^n�̴�
	*/
}