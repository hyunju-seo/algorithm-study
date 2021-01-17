#include<iostream>
#include<cstring>

#include<queue>
using namespace std;

char map[51][51];
int water[51][51];
int goseum[51][51];
const int forbidden = 10000;
const int unvisited = -1;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int r, c;

void waterGO(int startX,int startY) {
	queue<pair<int,int>> que;
	que.push({ startX,startY });
	water[startX][startY] = 0;
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int newx = x + dx[i];
			int newy = y + dy[i];
			if (newx < 0 || newy < 0 || newx >= r || newy >= c) continue;
			if (water[newx][newy] != unvisited) continue;
			water[newx][newy] = water[x][y] + 1;
			que.push({ newx,newy });
		}
	}
}

void goseumGO(int startX, int startY) {
	queue<pair<int, int>> que;
	que.push({ startX,startY });
	goseum[startX][startY] = 0;
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int newx = x + dx[i];
			int newy = y + dy[i];
			if (newx < 0 || newy < 0 || newx >= r || newy >= c) continue;
			if (goseum[newx][newy] != unvisited) continue;
			if (water[newx][newy]!=unvisited&&goseum[x][y] + 1 >= water[newx][newy]) continue;
			goseum[newx][newy] = goseum[x][y] + 1;
			que.push({ newx,newy });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(water, unvisited, sizeof(water));
	memset(goseum, unvisited, sizeof(goseum));
	int goseumx, goseumy;
	int biberx, bibery;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'D') {
				water[i][j] = forbidden; //물이 찰 수 없다
				biberx = i;
				bibery = j;
			}
			if (map[i][j] == 'S') {
				goseumx = i;
				goseumy = j;
				water[i][j] = forbidden; //물이 찰 수 없다

			}
			if (map[i][j] == 'X') {
				goseum[i][j] = forbidden;//고슴도치가 갈 수 없다.
				water[i][j] = forbidden; //물이 찰 수 없다

			}
			if (map[i][j] == '*') {
				goseum[i][j] = forbidden;//고슴도치가 갈 수 없다.
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == '*') {
				waterGO(i, j);
			}
		}
	}
	goseumGO(goseumx, goseumy);
	if (goseum[biberx][bibery] == unvisited) cout << "KAKTUS";
	else cout << goseum[biberx][bibery];
}