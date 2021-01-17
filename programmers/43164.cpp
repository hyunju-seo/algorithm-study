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

//airport의 index를 반환하는 함수
int airportIndex(string name) {
    return find(airport.begin(), airport.end(), name) - airport.begin();
}

//현재있는 airport에서 어디로 갈 수 있는지 경로를 정하는 함수
bool dfs(string airport) {

    //모든 경로를 방문하였을 경우
    if (isDone == 1) return true;
    int fromIdx = airportIndex(airport);

    //현재 airport(from)에서 이동할 수 있는 airport(to)
    for (int i = 0; i < route[fromIdx].size(); i++) {
        string to = route[fromIdx][i];
        int toIdx = airportIndex(to);
        if (canGo[fromIdx][toIdx] == 0) continue;
        canGo[fromIdx][toIdx] -= 1;
        isDone -= 1;
        ans.push_back(to);
        //만약 답을 구했다면 return 
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