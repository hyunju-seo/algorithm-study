#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<queue>
#include<cstdio>
#include<iostream>
using namespace std;
int n, m;
string board[55];
int group[55][55];  //0�湮 ���� , �� ��°�� �湮�� �������
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
pair<int, int>before[55][55]; //�ٷ� ������ �湮�� ���
bool bfs(int firstx, int firsty,char ch) {  //ch �湮 �� ���� , x y ���� ��ǥ
	queue<pair<int,int>> que;
	que.push({ firstx,firsty });
	group[firstx][firsty] = 1;
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		bool connect = false;

		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (nextX >= 0 || nextY >= 0 || nextX <= m || nextY <= n) {
				if (group[nextX][nextY] >= 4 && board[nextX][nextY] == ch && group[nextX][nextY] !=0) return true;

				if (board[nextX][nextY] == ch && group[nextX][nextY] ==0) {
					que.push({ nextX,nextY });
					group[nextX][nextY] = group[x][y]+1;

				}


			}

		}

	}
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
			cin >> board[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (group[i][j] == 0) { 
				bool ans=bfs(i, j, board[i][j]); 
				if (ans == true) {
					cout << "YES" << "\n";
					return 0;
				}
			}

		}
	}
	cout << "NO" << "\n";
	return 0;
}