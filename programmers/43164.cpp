//https://programmers.co.kr/learn/courses/30/lessons/43164
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include<iostream>
using namespace std;
int canGo[10001][10001];
vector<string> airport;
vector<string> route[10001];
vector<string> ans;
int isDone = 1;

//airport�� index�� ��ȯ�ϴ� �Լ�
int airportIndex(string name) {
    return find(airport.begin(), airport.end(), name) - airport.begin();
}

//�����ִ� airport���� ���� �� �� �ִ��� ��θ� ���ϴ� �Լ�
bool dfs(string airport) {

    //��� ��θ� �湮�Ͽ��� ���
    if (isDone == 1) return true;
    int fromIdx = airportIndex(airport);

    //���� airport(from)���� �̵��� �� �ִ� airport(to)
    for (int i = 0; i < route[fromIdx].size(); i++) {
        string to = route[fromIdx][i];
        int toIdx = airportIndex(to);
        if (canGo[fromIdx][toIdx] == 0) continue;
        canGo[fromIdx][toIdx] -= 1;
        isDone -= 1;
        ans.push_back(to);
        //���� ���� ���ߴٸ� return 
        if (dfs(to))return true;
        isDone += 1;
        ans.pop_back();
        canGo[fromIdx][toIdx] += 1;

    }
    return false;


}


vector<string> solution(vector<vector<string>> tickets) {
    set<string> temp;

    for (auto ticket : tickets) {
        isDone += 1;

        temp.insert(ticket[0]);
        temp.insert(ticket[1]);

    }
    for (auto t : temp) {
        airport.push_back(t);
    }
    for (auto ticket : tickets) {
        route[airportIndex(ticket[0])].push_back(ticket[1]);
        canGo[airportIndex(ticket[0])][airportIndex(ticket[1])] += 1;
    }
    for (int i = 0; i < airport.size(); i++) {
        sort(route[i].begin(), route[i].end());
    }

    vector<string> answer;
    ans.push_back("ICN");
    dfs("ICN");

    answer = ans;
    return answer;
}