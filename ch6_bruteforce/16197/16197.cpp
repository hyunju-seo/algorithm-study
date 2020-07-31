//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int board[30][30];
const auto coin = 1;
const auto wall = -1;
const auto blank = 0;
int n, m;
vector<int> answers;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool dropped(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) {
		return false;
	}
	return true;
}
bool isWall(int x, int y, int limit) {
	if (x >= 0 && y < limit) {
		if (board[x][y] == wall) { cout << "wall" << endl; return true; }
	}
	return false; 
}
void dropCoin(int x1, int y1, int x2, int y2, int num_move) {
	//
	cout<<"func: " << x1 << " " << y1 << "    ,    " << x2 << " " << y2 << endl;
	if (dropped(x1, y1) && !dropped(x2, y2)) {
		answers.push_back(num_move);
		return;
	}
	if (!dropped(x1, y1) && dropped(x2, y2)) {
		answers.push_back(num_move);
		return;
	}
	if (dropped(x1, y1) && dropped(x2, y2)) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		int tx1 = x1 + dx[i];
		int tx2 = x2 + dx[i];
		int ty1 = y1 + dy[i];
		int ty2 = y2 + dy[i];
		cout << tx1 << " " << ty1 << "    ,    " << tx2 << " " << ty2 << endl;
	//	cout << x1 + dx[i] << endl;
		if (isWall(tx1,ty1,n)  && isWall(tx2, ty2, m)) {
			cout << "both wall" << endl;
			continue;
		}


		if (isWall(tx1, ty1, n)) {
			cout << "1 wall" << endl;

		 tx1 = x1; ty1 = y1;
		}
		if (isWall(tx2, ty2, m)) {
			cout << "2 wall" << endl;

			 tx2 = x2; ty2 = y2; 
		}
		cout << "chdrhk" << endl;
		if (tx1 == tx2 && ty1 == ty2) continue;
		if (x1 == tx1 && x2 == tx2 && y1 == ty1 && y2 == ty2) continue;
		dropCoin(tx1, ty1, tx2, ty2, num_move + 1);

	}
} 
int main() {
	cin >> n >> m;
	//char inp;
	string inp;
	vector<pair<int,int>> startPosition;
	for (int i = 0; i < n; i++) {
		cin >> inp;
		for (int j = 0; j < m; j++)
		{
			//cout << "hey" << endl;
			//scanf("%1c", &inp);
			if (inp[j] == 'o') {
				board[i][j] = coin;
				startPosition.push_back({ i,j });
			}
			else if (inp[j] == '.') {
				board[i][j] = blank;

			}
			else if (inp[j] == '#') {
				board[i][j] = wall;

			}
		}
	}
	//for (int i = 0; i < n; i++) { 
	//	for (int j = 0; j < m; j++) {
	//		cout << board[i][j] << " ";
	//	}
	//	cout << endl;

	//}
	dropCoin(startPosition[0].first, startPosition[0].second, startPosition[1].first, startPosition[1].second,0);
	//cout << "hey" << endl;
	if (answers.empty()) {
		cout << -1;
	}
	else {
		cout << *max_element(answers.begin(), answers.end());

	}
}