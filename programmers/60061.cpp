//https://programmers.co.kr/learn/courses/30/lessons/60061
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int BO = 1;
const int GIDOONG = 0;
const int DELETE = 0;
const int INSTALL = 1;
int N;
bool gidoong[1001][1001];
bool bo[1001][1001];

//보가 x,y에 있을 수 있는지
bool checkBo(int x, int y) {
    if (y <= 0) return false;
    //한쪽 끝 부분이 기둥 위에 있거나
    if (y - 1 >= 0) {
        if (gidoong[x][y - 1]) return true;
        if (x + 1 <= N) {
            if (gidoong[x + 1][y - 1]) return true;
        }
    }
    // 양쪽 끝 부분이 다른 보와 동시에 연결
    if (x - 1 >= 0 && x + 1 < N) {
        if (bo[x - 1][y] && bo[x + 1][y]) return true;
    }
    return false;
}

bool checkGidoong(int x, int y) {
    // 바닥 위에 있거나 
    if (y == 0) return true;
    // 보의 한쪽 끝 부분 위에 있거나
    if (bo[x][y]) return true;
    if (x - 1 >= 0) {
        if (bo[x - 1][y]) return true;
    }
    //다른 기둥 위에 있어
    if (gidoong[x][y - 1]) return true;
    return false;
}


void deletes(int x, int y, int a) {
    bool answer = true;

    if (a == BO) {
        bo[x][y] = false;
        if (gidoong[x][y]) {
            if (!checkGidoong(x, y)) answer = false;
        }
        if (x + 1 <= N && gidoong[x + 1][y]) {
            if (!checkGidoong(x + 1, y)) answer = false;
        }
        if (x - 1 >= 0 && bo[x - 1][y]) {
            if (!checkBo(x - 1, y)) answer = false;
        }
        if (x + 1 < N && bo[x + 1][y]) {
            if (!checkBo(x + 1, y)) answer = false;
        }
        if (answer) bo[x][y] = false;
        else bo[x][y] = true;
        return;
    }
    else {
        gidoong[x][y] = false;
        if (y + 1 < N) {
            if (gidoong[x][y + 1] && !checkGidoong(x, y + 1)) answer = false;
            if (bo[x][y + 1] && !checkBo(x, y + 1)) answer = false;
            if (x - 1 >= 0) {
                if (bo[x - 1][y + 1] && !checkBo(x - 1, y + 1)) answer = false;
            }

        }

        //         if(bo[x][y]&&!checkBo(x,y)) answer=false;
        //         if(x-1>=0&&bo[x-1][y]&&!checkBo(x-1,y)) answer=false;
        if (answer) gidoong[x][y] = false;
        else gidoong[x][y] = true;
        return;
    }
}
void builds(int x, int y, int a) {
    if (a == BO) {
        //
        if (x + 1 > N) {
            bo[x][y] = false;
            return;
        }
        bo[x][y] = checkBo(x, y);
        return;

    }
    else {
        if (y + 1 > N) {
            gidoong[x][y] = false;
            return;
        }

        gidoong[x][y] = checkGidoong(x, y);
        return;

    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    N = n;
    vector<vector<int>> answer;
    for (auto build : build_frame) {
        int x = build[0];
        int y = build[1];
        int a = build[2];
        int b = build[3];
        if (b == DELETE) {
            deletes(x, y, a);
        }
        else {
            builds(x, y, a);
        }

    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (gidoong[i][j]) answer.push_back({ i,j,GIDOONG });
            if (bo[i][j]) answer.push_back({ i,j,BO });

        }
    }
    sort(answer.begin(), answer.end());


    return answer;
}