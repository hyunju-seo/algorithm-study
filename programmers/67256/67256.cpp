#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include<cstdlib>
using namespace std;
const int leftConst = 0;
const int rightConst = 1;
const int sameConst = 2;
pair<int, int> pos[10];
string answer = "";
pair<int, int> leftPos = make_pair(3, 0);
pair<int, int> rightPos = make_pair(3, 2);
int dis(int fingerx, int fingery, int posx, int posy) {
    return abs(fingerx - posx) + abs(fingery - posy);

}
void moveLeftFinger(int number) {
    answer += 'L';
    leftPos = make_pair(pos[number].first, pos[number].second);
}
void moveRightFinger(int number) {
    answer += 'R';
    rightPos = make_pair(pos[number].first, pos[number].second);
}
int findNearFinger(int number) {
    int leftdistance = dis(leftPos.first, leftPos.second, pos[number].first, pos[number].second);
    int rightdistance = dis(rightPos.first, rightPos.second, pos[number].first, pos[number].second);
    if (leftdistance == rightdistance) return sameConst;
    if (leftdistance > rightdistance) return rightConst;
    return leftConst;
}

string solution(vector<int> numbers, string hand) {
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            pos[x * 3 + y + 1] = make_pair(x, y);
        }
    }
    pos[0] = make_pair(3, 1);

    for (int i = 0; i < numbers.size(); i++) {
        int number = numbers[i];
        if (number == 1 || number == 4 || number == 7) {
            moveLeftFinger(number);
            continue;
        }
        else if (number == 3 || number == 6 || number == 9) {
            moveRightFinger(number);
            continue;
        }

        int res = findNearFinger(number);
        if (res == leftConst) {
            moveLeftFinger(number);
            continue;
        }
        else if (res == rightConst) {
            moveRightFinger(number);
            continue;
        }
        if (hand == "left") {
            moveLeftFinger(number);
            continue;
        }
        moveRightFinger(number);

    }



    return answer;
}