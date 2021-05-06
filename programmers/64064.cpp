//https://programmers.co.kr/learn/courses/30/lessons/64064
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
bool visited[9];
vector<int> banned_candidate[9];
set<string> ansSet;
void func(int groupidx, int groupNum, string str) {
    if (groupidx == groupNum) {
        sort(str.begin(), str.end());
        ansSet.insert(str);
        return;
    }
    for (int i = 0; i < banned_candidate[groupidx].size(); i++) {

        int now = banned_candidate[groupidx][i];
        if (visited[now]) continue;
        visited[now] = true;
        func(groupidx + 1, groupNum, str + to_string(now));
        visited[now] = false;
    }


}



int solution(vector<string> user_id, vector<string> banned_id) {
    for (int k = 0; k < banned_id.size(); k++) {
        string banned = banned_id[k];
        for (int i = 0; i < user_id.size(); i++) {
            string user = user_id[i];
            bool ans = true;
            for (int j = 0; j < banned.size(); j++) {
                if (banned[j] == '*') continue;
                if (banned[j] != user[j]) ans = false;
            }
            if (ans && banned.size() == user.size()) banned_candidate[k].push_back(i);
        }
    }

    func(0, banned_id.size(), "");

    int answer = ansSet.size();
    return answer;
}