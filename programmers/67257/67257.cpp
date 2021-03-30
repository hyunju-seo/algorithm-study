//https://programmers.co.kr/learn/courses/30/lessons/67257
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

long long solution(string expression) {

    string num = "";
    vector<long long> nums;
    vector<char> op;
    for (auto ch : expression) {
        if (ch >= '0' && ch <= '9') {
            num += ch;
        }
        else {
            op.push_back(ch);
            nums.push_back(stoll(num));
            num = "";
        }
    }
    nums.push_back(stoll(num));
    set<char> opset;
    for (auto o : op) {
        opset.insert(o);
    }

    vector<char> opPriority;
    for (auto s : opset) {
        opPriority.push_back(s);
    }
    sort(opPriority.begin(), opPriority.end());
    long long answer = 0;

    do {
        vector<long long> tnums = nums;
        vector<char> t_op = op;
        for (int idx = 0; idx < 3; idx++) {
            int i;
            for (i = 0; i < t_op.size();) {
                if (t_op[i] == opPriority[idx]) {
                    long long temp;
                    if (t_op[i] == '+') {
                        temp = tnums[i] + tnums[i + 1];
                    }
                    else if (t_op[i] == '-') temp = tnums[i] - tnums[i + 1];
                    else if (t_op[i] == '*') temp = tnums[i] * tnums[i + 1];
                    tnums.erase(tnums.begin() + i + 1);
                    t_op.erase(t_op.begin() + i);
                    tnums[i] = temp;
                }
                else i += 1;
            }
        }
        if (tnums[0] < 0) answer = max(answer, tnums[0] * (-1));
        else answer = max(answer, tnums[0]);

    } while (next_permutation(opPriority.begin(), opPriority.end()));

    return answer;
}