#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int dx[] = {1, 1, 2, 2, -1, -1, -2, -2 };
const int dy[] = {2, -2, 1, -1, 2, -2 ,1, -1};
int main() {
	int t; // number of testcases
	cin >> t;
	while (t != 0) {
		t--;
		int board[350][350];
		memset(board, -1, sizeof(board));
		int num; //number of spaces
		cin >> num; 
		int x, y; //position;
		int goX, goY; //purpose
		cin >> x >> y;
		cin >> goX >> goY;



		queue<pair<int, int >> que;
		
		que.push({ x,y });
		board[x][y] = 0;
		while (!que.empty()) {
			x = que.front().first;
			y = que.front().second;
			que.pop();
			if (x == goX && y == goY) {
				break;
			}
			for (int i = 0; i < 8; i++) {
				int nextX = x + dx[i];
				int nextY = y + dy[i];
				if (nextX >= 0 && nextY >= 0 && nextX < num && nextY < num) {
					if (board[nextX][nextY] == -1) {
						que.push({ nextX, nextY });
						board[nextX][nextY] = board[x][y] + 1;
					}
				}
			}
		}

		cout << board[goX][goY] << "\n";



	}
}