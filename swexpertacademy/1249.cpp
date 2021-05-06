#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include <cstdio>
#include<algorithm>
using namespace std;
int board[101][101];
int visited[101][101];
int n;
int answer;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
bool rangeCheck(int x) {
	if (x < 0 || x >= n) return false;
	return true;
}



//x,y 일때, 다음 좌표를 찾음
void dfs(int x, int y) {
	//cout << x << " " << y << endl;
	if (x == n - 1 && y == n - 1) {
		if (answer == -1)answer = visited[n - 1][n - 1];
		else answer = min(answer, visited[n - 1][n - 1]);
		return; 
	}
	if (answer!=-1 && visited[x][y] >= answer ) return;
	for (int i = 0; i < 4; i++) {
		//cout << i << endl;
		int nextx = x + dx[i];
		int nexty = y + dy[i];
		if (!rangeCheck(nextx) || !rangeCheck(nexty)) continue;
		//cout << "ss" << endl;
		
		if (visited[nextx][nexty] != -1 && visited[nextx][nexty] <= visited[x][y] + board[nextx][nexty]) continue;
		//cout << "jj" << endl;
		visited[nextx][nexty] = visited[x][y] + board[nextx][nexty];
		//cout << "op" << endl;

		dfs(nextx, nexty);
	}
}


int main() {
	int t;
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		answer = -1;
		scanf("%d", &n);

		memset(board, 0, sizeof(board));
		memset(visited, -1, sizeof(visited));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%1d",&board[i][j]);
			}
		}
		visited[0][0] = 0;
		dfs(0, 0);
		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << visited[i][j] << " ";
			}
		}*/
		cout << visited[n - 1][n - 1] << "\n";
	}


	return 0;

}