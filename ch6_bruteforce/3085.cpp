#include<iostream>
#include<algorithm>
using namespace std;
string board[50];
//int check(vector<string>& a) {
int check(string(&board)[50], const int n) {
	int ans = 1;
	for (int i = 0; i < n;i++) {
		int cnt = 1;
		for (int j = 1; j < n; j++) {
			if (board[i][j] == board[i][j - 1]) {
				cnt++;
			}
			else {
				cnt = 1;
			}
			ans = max(ans, cnt);
		}
		cnt = 1;
		for (int j = 1; j < n; j++) {
			if (board[j][i] == board[j - 1][i]) {
				cnt++;
			}
			else {
				cnt = 1;
			}
			ans = max(ans, cnt);
		}

	}
	return ans;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		
	}
	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {

			swap(board[i][j],board[i][j+1]);
			ans=max(check(board, n),ans);
			swap(board[i][j], board[i][j + 1]);

		}
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n; j++) {

			swap(board[i][j], board[i+1][j ]);
			ans = max(check(board, n), ans);
			swap(board[i][j], board[i + 1][j]);

		}
	}
	cout << ans;
}

