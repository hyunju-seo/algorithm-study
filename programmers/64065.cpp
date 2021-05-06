//https://programmers.co.kr/learn/courses/30/lessons/64065
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int visited[100001];
struct Set {
    int count;
    vector<int> vec;
    bool operator < (const Set& other) const {
        return count < other.count;
    }
};
vector<int> solution(string s) {

    vector<Set> vec;
    vector<int> tempvec;
    string str = "";
    int count = 0;
    for (auto temp : s) {

        if (temp == '{') { tempvec.clear(); count = 0; }
        else if (temp == '}') {
            if (str == "") continue;
            count += 1;
            tempvec.push_back(stoi(str));
            str = "";

            vec.push_back({ count, tempvec });
        }
        else if (temp == ',') {
            if (str == "") continue;
            count += 1;
            tempvec.push_back(stoi(str));
            str = "";
        }
        else {
            str += temp;
        }
    }
    vector<int> answer;
    sort(vec.begin(), vec.end());
    for (auto v : vec) {
        vector<int> tempv = v.vec;
        for (auto tv : tempv) {
            if (visited[tv]) continue;
            answer.push_back(tv);
            visited[tv] = true;
        }

    }

    return answer;
}