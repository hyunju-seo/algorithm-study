#include <string>
#include <vector>
#include <set>
#include<iostream>
using namespace std;
int answers[100001];

int main() {
    vector<string> gems = { "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };
    vector<int> answer;
    set<string> gemGroup;
    for (auto g : gems) {
        gemGroup.insert(g);
    }
    int totalNum = gemGroup.size();
    int len = gems.size();
    
    set<string> temp;
    for (int i = 0; i < len - totalNum + 1; i++) {
        temp.clear();
        for (int j = i; j < len; j++) {
            temp.insert(gems[j]);
            cout << temp.size()<<" " << totalNum << endl;
            if (temp.size() == totalNum) {
                answers[i] = j;
                break;
            }
        }
    }
    cout << endl;
    cout << "this" << endl;
    int minvalue = 100001;
    int minidx=0;
    for (int i = 0; i < len; i++) {
        cout << answers[i] << endl;
 
    }
    for (int i = 0; i < len; i++) {
        if (answers[i] == 0) continue;
        if (answers[i] - i < minvalue) {
            minidx = i;
            minvalue = answers[i] - i;
        }
    }
    answer.push_back(minidx + 1);
    answer.push_back(answers[minidx] + 1);
    cout << answer[0] << " " << answer[1] << endl;
}
