#include<iostream>
#include<queue>
using namespace std;
const int APPLE = 1;
const int SNAKE = 2;
const int NEGAONE = 2;
const int EMPTY = 0;
const int DELAPPLE = EMPTY;
const int DEL_TAIL = EMPTY;
int board[101][101];
queue<pair<int, char>> headDirection;
int n, k;

queue<pair<int, int>> snakeBody;

bool isWall(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n) return true;
	return false;
}

pair<int, int> changeHeadDirection(int dirx, int diry, char rl) {
	pair<int, int> ret;
	if (rl == 'D') {
		if (dirx == 0 && diry == 1)return { 1,0 };
		else if (dirx == 1 && diry == 0) return { 0,-1 };
		else if (dirx == -1 && diry == 0) return { 0,1 };
		else return { -1,0 };
	}
	else {
		if (dirx == 0 && diry == 1)return { -1,0 };
		else if (dirx == 1 && diry == 0) return { 0,1 };
		else if (dirx == -1 && diry == 0) return { 0,-1 };
		else return { 1,0 };
	}

}

int main() {

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		board[x - 1][y - 1] = APPLE;
	}
	int l;
	cin >> l;
	for (int i = 0; i < l; i++) {
		int x; char d;
		cin >> x >> d;
		headDirection.push({ x,d });
	}

	int headx = 0;
	int heady = 0;
	int sec = 0;
	int dirx = 0;
	int diry = 1;

	while (true) {
		if (!headDirection.empty()) {
			int nsec = headDirection.front().first;
			char rl = headDirection.front().second;
			if (sec == nsec) {
				headDirection.pop();
				pair<int, int> ret= changeHeadDirection(dirx, diry, rl);
				dirx = ret.first;
				diry = ret.second;
			}
		}		
		snakeBody.push({ headx, heady });
		board[headx][heady] = SNAKE;
		headx += dirx;
		heady += diry;
		sec += 1;
		if (isWall(headx, heady) || board[headx][heady] == SNAKE) break;

		if (board[headx][heady] == APPLE) {
			board[headx][heady] = DELAPPLE;
		}
		else {
			int tailx = snakeBody.front().first;
			int taily = snakeBody.front().second;
			snakeBody.pop();
			board[tailx][taily] = DEL_TAIL;
		}
	}
	cout << sec << "\n";
}