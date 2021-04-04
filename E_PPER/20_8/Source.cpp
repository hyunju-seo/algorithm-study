#include<iostream>

using namespace std;

bool se[15];
bool cross[50];
bool cross2[50];
bool cant[50][50];
int func(int i, int n) {

	if (i == n) {

		return 1;
	}
	int ret = 0;
	for (int j = 0; j < n; j++) {
		if (se[j]) continue;
		if (cross[j - i + n]) continue;
		if (cross2[n - j - i + n]) continue;
		if (cant[i][j]) continue;
		//cout << i << " " << j << endl;
		se[j] = true;
		cross2[n - j - i + n] = true;
		cross[j - i + n] = true;
		ret+=func(i + 1, n);
		se[j] = false;
		cross[j - i + n] = false;
		cross2[n - j - i + n] = false;
	}
	return ret;
}
void dofunc(int n, int k, int x[], int y[], int len) {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			cant[i][j] = false;
		}
	}
	for (int i = 0; i < len; i++) {
		cant[x[i] - 1][y[i] - 1] = true;
	}
	cout << func(0, n);
}

int main() {
	int x[] = { 1,1,1 };
	int y[] = { 1,2,3 };
	dofunc(5, 3, x, y,3);
	cout << "\n" << 4 << "\n" << "\n";

	int x1[] = { 1, 2, 3, 4, 5 };
	int y1[] = { 2, 2, 3, 4, 5 };
	dofunc(6, 5, x1, y1,5);	
	cout << "\n" << 3 << "\n" << "\n";

	int x2[] = { 3, 3, 3, 3, 3, 3, 3 };
	int y2[] = { 1, 2, 3, 4, 5, 6, 7 };
	dofunc(7, 7, x2, y2,7);	
	cout << "\n" << 0 << "\n" << "\n";

	int x3[] = { 11, 10, 9, 1, 3, 5, 7, 2, 4, 2, 1 };
	int y3[] = { 10, 9, 11, 11, 6, 4, 3, 2, 6, 3, 10 };
	dofunc(11, 11, x3, y3,11);
	cout<<"\n" << 1031 << "\n"<<"\n";
	int x4[] = { 1,1,1 };
	int y4[] = { 1,2,3 };
	dofunc(5, 3, x4, y4,3);
}