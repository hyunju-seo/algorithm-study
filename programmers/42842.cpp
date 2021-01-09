//https://programmers.co.kr/learn/courses/30/lessons/42842
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for (int se = 1; se <= sqrt(yellow); se++) {
        if (yellow % se != 0) continue;
        int ga = yellow / se;
        if ((ga + 2) * (se + 2) == brown + yellow) {
            answer.push_back(ga + 2);
            answer.push_back(se + 2);
            break;
        }
    }
    return answer;
}