//https://www.acmicpc.net/problem/16236
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#include<tuple>

using namespace std;
int n;
int sharkSize = 2;
const int shark = 9;
const int non = 0;
int board[21][21];
int answer = 0;
int eat = 0;
int sharkx;
int sharky;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool movable(int x, int y) {
	if (board[x][y] <= sharkSize) return true;
	return false;
}

bool go() {
	board[sharkx][sharky] = 0;
	int visited[21][21];
	memset(visited, -1, sizeof(visited));
	queue<pair<int, int>> que;
	vector < tuple<int, int, int>> eatList;
	visited[sharkx][sharky] = 0;
	que.push({ sharkx,sharky });
	while (!que.empty()) {
		sharkx = que.front().first;
		sharky = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nextx = sharkx + dx[i];
			int nexty = sharky + dy[i];
			if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= n) continue;
			if (!movable( nextx, nexty)) continue;
			if (visited[nextx][nexty]!=-1) continue;
			visited[nextx][nexty] = visited[sharkx][sharky] + 1;
			que.push({nextx,nexty});
			if (board[nextx][nexty] != 0 && board[nextx][nexty] < sharkSize) eatList.push_back({ visited[nextx][nexty],nextx,nexty });

		}
	}
	if (eatList.empty()) return false;

	sort(eatList.begin(), eatList.end());
	eat += 1;
	if (eat == sharkSize) {
		sharkSize += 1;
		eat = 0;
	}
	int distance = get<0>(eatList[0]);
	sharkx = get<1>( eatList[0]);
	sharky = get<2>(eatList[0]);
	answer += distance;
	return true;

}
void repeat() {
	int ret = go();
	if (ret) repeat();
}


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == shark) {
				sharkx = i;
				sharky = j;
			}
		}
	}
	

	repeat();
	cout << answer << "\n";

}