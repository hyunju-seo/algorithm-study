#include<iostream>
using namespace std;
int d[16][29][20];//현재 연도 구하기
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int E, S, M;
	cin >> E >> S >> M;
	int e, s, m;
	e = s = m = 1;
	int year = 1;
	while (year <= 15 * 28 * 19) {
		d[e][s][m] = year;
		year++;
		if (e < 15)e++;
		else e = 1;
		if (s < 28) s++;
		else s = 1;
		if (m < 19)m++;
		else m = 1;
	}
	cout << d[E][S][M]<<"\n";
}