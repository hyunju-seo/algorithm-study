//https://programmers.co.kr/learn/courses/30/lessons/60059#
#include <string>
#include <vector>
#include <iostream>

using namespace std;


//rotation
vector<vector<int>> rotateKey(vector<vector<int>> key) {
    vector<vector<int>> temp(key.size(), vector<int>(key.size(), 0));
    for (int i = 0, tj = 0; i < key.size(); i++, tj++) {
        for (int j = 0, ti = key.size() - 1; j < key.size(); j++, ti--) {
            temp[i][j] = key[ti][tj];
        }
    }
    return temp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    vector<vector<int>> templock;
    int n = lock.size();
    int m = key.size();
    vector<vector<int>> board(2 * m + n - 2, vector<int>(2 * m + n - 2, 0));
    vector<vector<int>> boardTemp; //계산용

    int lockstart = m - 1;
    int lockend = m + n - 2;
    for (int i = lockstart, li = 0; i <= lockend; i++, li++) {
        for (int j = lockstart, lj = 0; j <= lockend; j++, lj++) {
            board[i][j] = lock[li][lj];
        }
    }


    bool answer;

    //rotation
    for (int ro = 0; ro < 4; ro++) {

        //key 상하좌우로 이동
        for (int i = 0; i <= lockend; i++) {
            for (int j = 0; j <= lockend; j++) {
                boardTemp = board;
                answer = true;
                //board+key
                for (int p = 0, bi = i; p < m; p++, bi++) {
                    for (int q = 0, bj = j; q < m; q++, bj++)
                        boardTemp[bi][bj] += key[p][q];
                }

                //답 check
                for (int p = lockstart; p <= lockend; p++) {
                    for (int q = lockstart; q <= lockend; q++) {
                        if (boardTemp[p][q] != 1)  answer = false;
                    }
                }
                if (answer == true) return true;
            }
        }
        key = rotateKey(key);
    }


    return false;
}