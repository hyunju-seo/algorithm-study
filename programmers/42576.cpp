//https://programmers.co.kr/learn/courses/30/lessons/42576
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<string, bool>> dic[30];

string solution(vector<string> participant, vector<string> completion) {
    for (auto c : completion) {
        dic[c[0] - 'a'].push_back({ c,false });
    }
    string answer = "";

    for (auto p : participant) {
        auto& myDic = dic[p[0] - 'a'];
        bool ans = true;
        for (int i = 0; i < myDic.size(); i++) {
            if (myDic[i].first == p && myDic[i].second == false) {
                ans = false;
                myDic[i].second = true;
                break;
            }
        }
        if (ans) {
            answer = p;
            break;
        }

    }
    return answer;
}

//다른 풀이
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//string solution(vector<string> participant, vector<string> completion) {
//    sort(participant.begin(), participant.end());
//    sort(completion.begin(), completion.end());
//    string answer = "";
//    bool ans = false;
//    for (int i = 0; i < completion.size(); i++) {
//        if (completion[i] != participant[i]) {
//            answer = participant[i];
//            ans = true;
//            break;
//        }
//    }
//    if (ans == false) {
//        answer = participant.back();
//    }
//
//
//    return answer;
//}