#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
char board[30][30];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int r, c;

int alphabetToNum(char alpha) {
	return alpha - 'A';
}
vector<int> answers;

//x,y에서 어떤 칸으로 이동할 지
void move(int x, int y, int num, bool visited[30]) {
	bool end = true;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX < 0 || nextY < 0 || nextX >= r || nextY >= c) continue;
		char nextAlphabet = board[nextX][nextY];
		if (visited[alphabetToNum(nextAlphabet)]) continue;
		visited[alphabetToNum(nextAlphabet)] = true;
		move(nextX, nextY, num + 1, visited);
		visited[alphabetToNum(nextAlphabet)] = false;

		end = false;
	}
	if (end) {
		answers.push_back(num);
		return;
	}
}


int main() {

	cin >> r >> c;
	//for (int i = 0; i < r; i++) {
	//	for (int j = 0; j < c; j++) {
	//		scanf("%1c", &board[i][j]);
	//	}
	//}
	string str;
	for (int i = 0; i < r; i++) {
		cin >> str;
		for (int j = 0; j < c; j++) {
			board[i][j] = str[j];

		}
	}

	bool visited[30] = { 0 };

	visited[alphabetToNum(board[0][0])] = true;
	move(0, 0, 1,visited);
	cout << *max_element(answers.begin(), answers.end())<<"\n";
}