#include<iostream>
int a[10];
using namespace std;

//자연수 index가 수열에 포함 되는지 안되는지를 정하는 함수
void go(int index, int selected, int n, int m) {    //selected : 수열에 몇개가 있는지
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
	15650.cpp의 시간 복잡도는 n!이지만 
	이 풀이 방법은 시간 복잡도가 2^n이다
	*/
}