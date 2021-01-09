//https://programmers.co.kr/learn/courses/30/lessons/42748
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int i, j, k;
    vector<int> part;
    for (auto t : commands) {
        part.clear();
        i = t[0] - 1;
        j = t[1] - 1;
        k = t[2] - 1;
        for (int idx = i; idx <= j; idx++) {
            part.push_back(array[idx]);
        }
        sort(part.begin(), part.end());
        answer.push_back(part[k]);

    }
    return answer;
}