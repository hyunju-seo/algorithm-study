//https://programmers.co.kr/learn/courses/30/lessons/42578
#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;
unordered_map<string, int> map;

int solution(vector<vector<string>> clothes) {

    for (auto c : clothes) {
        map[c[1]] += 1;
    }
    int answer = 1;
    for (auto m : map) {
        answer *= (m.second + 1);
    }
    answer -= 1;
    return answer;
}
