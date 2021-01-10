//https://programmers.co.kr/learn/courses/30/lessons/43163
#include <string>
#include <vector>
#include<queue>
#include<algorithm>
using namespace std;
bool canChange(string str1, string str2) {
    int diff = 0;
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] != str2[i]) diff++;
    }
    if (diff == 1) return true;
    else return false;
}
int bfs(string start, string target, vector<string> words) {
    vector<string> visited;
    visited.push_back(start);
    queue<pair<string, int>> que;
    que.push({ start,0 });
    while (!que.empty()) {
        string f = que.front().first;
        int s = que.front().second;
        que.pop();
        for (auto w : words) {
            if (!canChange(w, f)) continue;
            if (find(visited.begin(), visited.end(), w) != visited.end()) continue;
            if (w == target) {
                return s + 1;
            }
            visited.push_back(w);
            que.push({ w,s + 1 });
        }
    }
    return 0;

}

int solution(string begin, string target, vector<string> words) {

    int answer = bfs(begin, target, words);
    return answer;
}