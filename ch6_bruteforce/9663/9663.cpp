#include<iostream>
using namespace std;
//
int n;
int sum = 0;

bool impossible[20][20];
void space(int i, int j , bool boo) {
	int dx[] = { 1,-1,-1,1 };
	int dy[] = { -1,1,-1,1 };
	impossible[i][j] = boo;
	for (int idx = 0; idx < n; idx++) {

		impossible[idx][j] = boo;
		impossible[i][idx] = boo;
	}


	for (int idx = 0; idx < 4; idx++) {
		int tempx = i;
		int tempy = j;
		while (true) {

			
			tempx = tempx + dx[idx];
			tempy = tempy + dy[idx];
			if (tempx < 0 || tempy < 0 || tempx >= n || tempy >= n) break;

			impossible[tempx][tempy] = boo;
		}
	}



}

void chess(int queennum) {
	bool contin=false;
	for (int i = 0; i < n; i++) {
		if (contin == true) break;
		for (int j = 0; j < n; j++) {
			if (!impossible[i][j]) {
				contin = true; break;
			}
		}

	}
	if (contin == false) return;
	if (queennum == n) { sum++; return; }
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!impossible[i][j]) {
				space(i, j, true);
				chess(queennum + 1);
				space(i, j, false);

			}
		}
	}
}



int main() {
	cin >> n;
	chess(0);
	cout << sum << "\n";

}