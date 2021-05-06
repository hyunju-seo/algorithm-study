#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int boardSize = board.size();
    vector<stack<int>> stk(boardSize);
    for (int i = boardSize - 1; i >= 0; i--) {
        for (int j = 0; j < boardSize; j++) {
            if (board[i][j] == 0) continue;
            stk[j].push(board[i][j]);
        }
    }
    stack<int> basket;
    for (int m : moves) {
        if (stk[m - 1].empty()) continue;
        int doll = stk[m - 1].top();
        stk[m - 1].pop();
        if (basket.empty()) basket.push(doll);
        else {
            if (basket.top() == doll) {
                answer += 2;
                basket.pop();
            }
            else {
                basket.push(doll);
            }
        }
    }


    return answer;
}