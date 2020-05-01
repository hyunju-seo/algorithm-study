//종만북 152P
#include<iostream>
#include<vector>
using namespace std;
vector<pair<int, int>> direction = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
char board[5][5];

bool go(const string& str, int y, int x) {
	//X,Y 가 시작위치 밖일 경우
	if (y > 5 || x > 5 || y < 0 || x < 0) {
		return false; }
	//첫 글자가 다를 경우
	if (str[0] != board[x][y]) {

		return false;
	}
	if (str.size() == 1) return true;
	//인접한 8칸 모두 검사
	for (int i = 0; i < 8; i++) {
		int nextY = y+direction[i].first;
		int nextX = x+direction[i].second;
		bool result= go(str.substr(1), nextY, nextX);
		if (result == true) return true;
	}
	return false;
}
int main() {
	string str;
	cin >> str;
	int y, x;
	bool first = false;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
			if (board[i][j] == str[0]&&first==false) {
				y = j;
				x = i;
				first = true;
			}
		}
	}
	cout<< go(str, y, x);
}