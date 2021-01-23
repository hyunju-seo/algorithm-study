//https://programmers.co.kr/learn/courses/30/lessons/60057
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
int strsize;
string str;

int cal(int cut, int f, int s, int cumul) {
    if (s >= strsize) {
        if (cumul >= 2) return cut + to_string(cumul).size();
        else return strsize - f;

    }
    if (str.substr(f, cut) == str.substr(s, cut))
        return cal(cut, f + cut, s + cut, cumul + 1);

    else {
        if (cumul >= 2)
        {
            return cal(cut, f + cut, s + cut, 1) + cut + to_string(cumul).size();
        }
        else {
            return cal(cut, f + cut, s + cut, 1) + cut;
        }
    }

}

int solution(string s) {
    str = s;
    strsize = s.size();
    int answer = 1001;
    for (int i = 1; i <= (strsize + 1) / 2; i++) {
        answer = min(answer, cal(i, 0, 0 + i, 1));
    }
    return answer;
}