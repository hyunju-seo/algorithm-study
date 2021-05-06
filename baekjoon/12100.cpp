#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<cstring>
using namespace std;
int board[21][21];
int n;
const int LEFT = 0;
const int RIGHT = 1;
const int UP = 2;
const int DOWN = 3;
int direc[] = { LEFT, RIGHT, UP, DOWN };
int maxNum = 0;
void move(int cnt, int board[21][21]) {
	if (cnt > 4) return;

	stack<int> stk;
	int newBoard[21][21];
	memset(newBoard, 0, sizeof(newBoard));
	//왼쪽으로 이동
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(board[i][j]!=0) stk.push(board[i][j]);
		}
		int idx = 0;
		while (!stk.empty()) {
			int a = stk.top();
			stk.pop();
			if (!stk.empty()) {
				int b = stk.top();
				stk.pop();
				if (a == b) {
					newBoard[i][idx] = a + b;
					maxNum = max(a + b, maxNum);
				}
				else {
					newBoard[i][idx] = a;
					stk.push(b);
				}
			}
			else {
				newBoard[i][idx] = a;
			}
			idx += 1;
		}

	}
	move(cnt + 1, newBoard);

	memset(newBoard, 0, sizeof(newBoard));
	//오른쪽으로 이동
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (board[i][j] != 0) stk.push(board[i][j]);
		}
		int idx = n-1;
		while (!stk.empty()) {
			int a = stk.top();
			stk.pop();
			if (!stk.empty()) {
				int b = stk.top();
				stk.pop();
				if (a == b) {
					newBoard[i][idx] = a + b;
					maxNum = max(a + b, maxNum);
				}
				else {
					newBoard[i][idx] = a;
					stk.push(b);
				}
			}
			else {
				newBoard[i][idx] = a;
			}
			idx -= 1;
		}
	}
	move(cnt + 1, newBoard);

	memset(newBoard, 0, sizeof(newBoard));
	//위로 이동
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			if (board[i][j] != 0) stk.push(board[i][j]);
		}
		int idx = 0;
		while (!stk.empty()) {
			int a = stk.top();
			stk.pop();
			if (!stk.empty()) {
				int b = stk.top();
				stk.pop();
				if (a == b) {
					newBoard[idx][j] = a + b;
					maxNum = max(a + b, maxNum);
				}
				else {
					newBoard[idx][j] = a;
					stk.push(b);
				}
			}
			else {
				newBoard[idx][j] = a;
			}
			idx += 1;
		}
	}
	move(cnt + 1, newBoard);

	memset(newBoard, 0, sizeof(newBoard));
	//아래로 이동
	for (int j = 0; j < n; j++) {
		for (int i = n - 1; i >= 0; i--) {
			if (board[i][j] != 0) stk.push(board[i][j]);

		}
		int idx = n-1;
		while (!stk.empty()) {
			int a = stk.top();
			stk.pop();
			if (!stk.empty()) {
				int b = stk.top();
				stk.pop();
				if (a == b) {
					newBoard[idx][j] = a + b;
					maxNum = max(a + b, maxNum);
				}
				else {
					newBoard[idx][j] = a;
					stk.push(b);
				}
			}
			else {
				newBoard[idx][j] = a;
			}
			idx -= 1;
		}
	}
	move(cnt + 1, newBoard);

}


int main() {
	cin >> n;

	int board[21][21];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			maxNum=max(board[i][j], maxNum);
		}
	}
	move(0, board);
	cout << maxNum << "\n";
}