//https://programmers.co.kr/learn/courses/30/lessons/60063
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
#include <algorithm>

#include <iostream>

using namespace std;
int n;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int visited[101][101][101][101];

bool rangeCheck(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return false;
    return true;
}
vector<tuple<int, int, int, int>> rotation(int xa, int ya, int xb, int yb, vector<vector<int>> board) {
    int x1, x2, y1, y2;
    vector<pair<int, int>> vec;
    vec.push_back({ xa,ya });
    vec.push_back({ xb,yb });
    sort(vec.begin(), vec.end());
    x1 = vec[0].first;
    y1 = vec[0].second;
    x2 = vec[1].first;
    y2 = vec[1].second;
    vector<tuple<int, int, int, int>> ret;
    if (x1 == x2) {
        //x1,y1축
        if (rangeCheck(x1 + 1, y1 + 1) && board[x1 + 1][y1 + 1] != 1)
            ret.push_back({ x1,y1,x1 + 1,y1 });
        if (rangeCheck(x1 - 1, y1 + 1) && board[x1 - 1][y1 + 1] != 1)
            ret.push_back({ x1,y1,x1 - 1,y1 });
        //x2,y2축
        if (rangeCheck(x2 + 1, y2 - 1) && board[x2 + 1][y2 - 1] != 1)
            ret.push_back({ x2 + 1,y2,x2,y2 });
        if (rangeCheck(x2 - 1, y2 - 1) && board[x2 - 1][y2 - 1] != 1)
            ret.push_back({ x2 - 1,y2,x2,y2 });
    }
    if (y1 == y2) {
        //x1,y1축
        if (rangeCheck(x1 + 1, y1 + 1) && board[x1 + 1][y1 + 1] != 1)
            ret.push_back({ x1,y1,x1,y1 + 1 });
        if (rangeCheck(x1 + 1, y1 - 1) && board[x1 + 1][y1 - 1] != 1)
            ret.push_back({ x1,y1,x1,y1 - 1 });
        //x2,y2축
        if (rangeCheck(x2 - 1, y2 - 1) && board[x2 - 1][y2 - 1] != 1)
            ret.push_back({ x2,y2 - 1,x2,y2 });
        if (rangeCheck(x2 - 1, y2 + 1) && board[x2 - 1][y2 + 1] != 1)
            ret.push_back({ x2,y2 + 1,x2,y2 });
    }
    return ret;

}
void bfs(vector<vector<int>> board) {
    memset(visited, -1, sizeof(visited));
    int x1 = 0, y1 = 0, x2 = 0, y2 = 1;
    visited[x1][y1][x2][y2] = 0;
    visited[x2][y2][x1][y1] = 0;
    queue<tuple<int, int, int, int>> que;
    que.push({ x1,y1,x2,y2 });
    while (!que.empty()) {
        tie(x1, y1, x2, y2) = que.front();
        que.pop();
        int nextX1, nextY1, nextX2, nextY2;
        //상하좌우 이동
        for (int i = 0; i < 4; i++) {
            nextX1 = x1 + dx[i];
            nextY1 = y1 + dy[i];
            nextX2 = x2 + dx[i];
            nextY2 = y2 + dy[i];
            if (!rangeCheck(nextX1, nextY1) || !rangeCheck(nextX2, nextY2)) continue;
            if (visited[nextX1][nextY1][nextX2][nextY2] != -1 || visited[nextX2][nextY2][nextX1][nextY1] != -1) continue;
            if (board[nextX1][nextY1] == 1 || board[nextX2][nextY2] == 1) continue;
            visited[nextX1][nextY1][nextX2][nextY2] = visited[x1][y1][x2][y2] + 1;
            visited[nextX2][nextY2][nextX1][nextY1] = visited[x1][y1][x2][y2] + 1;
            que.push({ nextX1,nextY1,nextX2,nextY2 });

        }
        //회전
        vector<tuple<int, int, int, int>>ret = rotation(x1, y1, x2, y2, board);
        for (auto r : ret) {
            tie(nextX1, nextY1, nextX2, nextY2) = r;
            if (!rangeCheck(nextX1, nextY1) || !rangeCheck(nextX2, nextY2)) continue;
            if (visited[nextX1][nextY1][nextX2][nextY2] != -1 || visited[nextX2][nextY2][nextX1][nextY1] != -1) continue;
            if (board[nextX1][nextY1] == 1 || board[nextX2][nextY2] == 1) continue;
            visited[nextX1][nextY1][nextX2][nextY2] = visited[x1][y1][x2][y2] + 1;
            visited[nextX2][nextY2][nextX1][nextY1] = visited[x1][y1][x2][y2] + 1;
            que.push({ nextX1,nextY1,nextX2,nextY2 });
        }
    }

}


int solution(vector<vector<int>> board) {
    int answer = 0;
    n = board.size();
    bfs(board);
    int a = visited[n - 1][n - 2][n - 1][n - 1];
    int b = visited[n - 2][n - 1][n - 1][n - 1];
    if (a == -1) answer = b;
    else if (b == -1) answer = a;
    else answer = min(a, b);



    return answer;
}