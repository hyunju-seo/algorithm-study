#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int s = 0;
int map[105][105]; //섬 or 바다 표시
int color[105][105];  //섬의 종류
int n;
int a = 0;
bool checked[105][105]; //다리 후보로 고려됨
int step[105][105];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
void bridge(int x,int y, int c) {
	//cout <<"color "<< c << endl;
	queue<pair<int,int>> que;
	step[x][y] = 1;
	que.push({ x,y });
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) continue;
			if (map[nextX][nextY] != 0 && color[nextX][nextY] != c) {
				//cout << "color " <<s color[nextX][nextY] << endl;
				a = step[x][y];
				return; }
			if (map[nextX][nextY] == 0 && step[nextX][nextY]==0) {
				que.push({ nextX,nextY });

				step[nextX][nextY] = step[x][y] + 1;
			}
			

		}
	}
}
void bfs(int x, int y) {
	queue<pair<int, int>> que;
	color[x][y] = s;
	que.push({ x,y });
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) continue;
			if (map[nextX][nextY] == 1 && color[nextX][nextY] == 0) {
				que.push({ nextX,nextY });
				color[nextX][nextY] = s;
			}

		}
	}
}


int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			if (color[i][j] == 0 && map[i][j] == 1) {
				s++;
				bfs(i, j);
			}
		}
	}
	if (s == 1) {
		cout << 0 << endl;
		return 0;
	}
	
	int candi = -1;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (color[x][y] == 0) continue;
			for (int i = 0; i < 4; i++) {
				int nextX = x + dx[i];
				int nextY = y + dy[i];
				if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) continue;
				if (map[nextX][nextY] != 0 || checked[nextX][nextY] == true) continue;
				checked[nextX][nextY] = true;
				a = 0;
				memset(step, 0, sizeof(step));
				bridge(nextX, nextY, color[x][y]);
				//cout << endl;

				//for (int kr = 0; kr < n; kr++) {
				//	for (int kb = 0; kb < n; kb++) {
				//		cout << step[kr][kb] << " ";
				//	}cout << endl;
				//}
				//cout << endl;
				if (candi == -1) candi = a;
				else candi = min(a, candi);
			}
		}
	}

	cout << candi;
}