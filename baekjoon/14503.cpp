#include<iostream>
using namespace std;
int map[51][51];
int n, m;

pair<int, int > rotation(int dx, int dy) {
	if (dx == -1 && dy == 0) return { 0,-1 };
	if (dx == 0 && dy == -1) return { 1,0 };
	if (dx == 1 && dy == 0) return { 0,1 };
	if (dx == 0 && dy == 1) return { -1,0 };
}
int ans = 0;
bool iswall(int x, int y) {
	if (x < n && y < m && x >= 0 && y >= 0) {
		if(map[x][y]!=1)
			return false;
	} return true;
}

void move(int x, int y , int dx, int dy) {
	//cout << x << " " << y << " " << dx << " " << dy << endl;
	if (map[x][y] == 0) {
		map[x][y] = 2;
		ans += 1;
	}
	pair<int, int> rot;
	int rotdx = dx;
	int rotdy = dy;
	int leftx, lefty;
	bool canClean = false;

	for (int i = 0; i < 4; i++) {
		rot = rotation(rotdx, rotdy);
		rotdx = rot.first;
		rotdy = rot.second;
		leftx = x + rotdx;
		lefty = y + rotdy;
		if (!iswall(leftx, lefty) && map[leftx][lefty] == 0) {
			move(leftx, lefty, rotdx, rotdy);
			canClean = true;
			break;
		}
	}
	

	
	if (!canClean) {
		int backx = x - dx;
		int backy = y - dy;
		if (iswall(backx, backy)) return ;
		move(backx, backy, dx, dy);
	}

	return ;
}
int main() {
	cin >> n >> m;
	int r, c, d;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	
	int dx, dy;
	if (d == 0) {//ºÏ
		dx = -1;
		dy = 0;
	}
	else if (d == 1) { //µ¿
		dx = 0;
		dy = 1;
	}
	else if (d == 2) { //³²
		dx = 1; dy = 0;
	}
	else { //¼­
		dx = 0;
		dy = -1;
	}
	move(r, c, dx, dy);
	cout << ans << "\n";
}