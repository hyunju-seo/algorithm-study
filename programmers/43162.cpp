//https://programmers.co.kr/learn/courses/30/lessons/43162
#include <string>
#include <vector>
#include <queue>

using namespace std;
bool visited[201];
void bfs(int start, int n, vector<vector<int>> computers) {
    queue<int> que;
    visited[start] = true;
    que.push(start);
    while (!que.empty()) {
        int f = que.front();
        que.pop();
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            if (computers[f][i] == 1) {
                visited[i] = true;
                que.push(i);
            }
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        bfs(i, n, computers);
        answer += 1;
    }
    return answer;
}