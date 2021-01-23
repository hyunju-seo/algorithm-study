//https://programmers.co.kr/learn/courses/30/lessons/42577
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> phone[10];
bool solution(vector<string> phone_book) {
    bool answer = true;

    for (auto phoneNumber : phone_book) {
        phone[phoneNumber[0] - '0'].push_back(phoneNumber);
    }
    for (int i = 0; i < 10; i++) {
        sort(phone[i].begin(), phone[i].end());
        if (answer == false) break;
        for (int j = 0; j < phone[i].size(); j++) {
            for (int k = j + 1; k < phone[i].size(); k++) {
                string phone1 = phone[i][j];
                string phone2 = phone[i][k];
                if (phone2.substr(0, phone1.size()) == phone1) {
                    answer = false;
                    break;
                }
            }
            if (answer == false) break;

        }
    }

    return answer;
}