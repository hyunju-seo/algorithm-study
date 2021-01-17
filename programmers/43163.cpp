//https://programmers.co.kr/learn/courses/30/lessons/43163
#include <string>
#include <vector>
#include<queue>
#include<algorithm>
using namespace std;
bool visited[51];

bool canChange(string str1, string str2) {
    int diff = 0;
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] != str2[i]) diff++;
    }
    if (diff == 1) return true;
    else return false;
}
int bfs(string start, string target, vector<string> words) {
    queue<pair<string, int>> que;
    que.push({ start,0 });
    while (!que.empty()) {
        string f = que.front().first;
        int s = que.front().second;
        que.pop();
        for (int i = 0; i < words.size(); i++) {
            string w = words[i];
            if (!canChange(w, f)) continue;
            if (visited[i]) continue;
            if (w == target) {
                return s + 1;
            }
            visited[i] = true;
            que.push({ w,s + 1 });
        }
    }
    return 0;

}

int solution(string begin, string target, vector<string> words) {
    int f = find(words.begin(), words.end(), begin) - words.begin();
    if (f < 51 && f >= 0) visited[f] = true;
    int answer = bfs(begin, target, words);

    return answer;
}