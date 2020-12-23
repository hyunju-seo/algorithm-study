#include<iostream>
#include<queue>
#include<tuple>

using namespace std;

const char wall = '#';
const char emptyspace = '.';
char chess[20][20][20];
bool visited[20][20][20];
int dx[] = {0, 0,0,1,-1, -1, -1, 1, 1 };
int dy[] = {0, 1,-1,0,0, 1,  -1, -1 ,1 };

void movewall() {

	for (int k = 1; k <= 8; k++) {
		for (int i = 7; i != 0; i--) {
			for (int j = 0; j < 8; j++) {
				chess[k][i][j] = chess[k-1][i - 1][j];
			}
		}
		for (int j = 0; j < 8; j++) {
			chess[k][0][j] = emptyspace;
		}
	}


}


bool checkwall(int chessnum, int x, int y) {
	chessnum = chessnum + 1;
	if (chessnum > 8) chessnum = 8;
	if (chess[chessnum][x][y] == wall) return true;
	return false;
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 8; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 8; j++) {
			chess[0][i][j] = str[j];
		}
	}
	movewall();

	int startx = 7;
	int starty = 0;
	int endx = 0;
	int endy = 7;
	queue < tuple <int, int, int> > que;
	que.push(make_tuple( -1,startx, starty ));
	visited[0][startx][starty] = true;
	while (!que.empty()) {
		int cnum, x, y;
		tie(cnum, x, y) = que.front();
		que.pop();
		int nextcnum = cnum + 1;
		if (nextcnum > 8) nextcnum = 8;

		for (int i = 0; i <= 8; i++) {
			int nextx = x + dx[i];
			int nexty = y + dy[i];
			if (nextx < 0 || nexty < 0 || nextx >= 8 || nexty >= 8) continue;
			if (chess[nextcnum][nextx][nexty] == wall || visited[nextcnum][nextx][nexty]) continue;
			if (checkwall(nextcnum, nextx, nexty)) continue;
			que.push(make_tuple(nextcnum, nextx,nexty ));
			visited[nextcnum][nextx][nexty] = true;
		}

	}
	for (int i = 0; i <= 8; i++) {
		if (visited[i][endx][endy]) {
			cout << 1 << "\n";
			return 0;
		}
	}
	cout << 0 << "\n";
	return 0;

}