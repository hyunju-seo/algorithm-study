//https://www.acmicpc.net/problem/2667
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int num;
int houses[26][26];
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };


int bfs(int x, int y) {
	int result = 0;
	queue<pair<int, int>>que;
	houses[x][y] = 2;
	result++;
	que.push({ x,y });
	while (!que.empty()) {
		x = que.front().first;
		y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (nextX >= num || nextX < 0 || nextY < 0 || nextY >= num) continue;
			if (houses[nextX][nextY] == 1) {
				que.push({ nextX,nextY });
				result++;
				houses[nextX][nextY] = 2;
			}


		}
	}
	return result;
}
int main() {
	
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			scanf("%1d", &houses[i][j]);
		}
	}

	int complex = 0;
	vector<int> ans_list;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (houses[i][j] == 1) {
				ans_list.push_back(bfs(i, j));
				complex += 1;
			}
		}
	}
	sort(ans_list.begin(), ans_list.end());
	cout << complex << "\n";
	for (auto li:ans_list) {
		cout << li<<"\n";
		
	}

	
}