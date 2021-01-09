//https://programmers.co.kr/learn/courses/30/lessons/43165
#include <string>
#include <vector>

using namespace std;
int tanswer = 0;
void func(int idx, vector<int> numbers, int sum, int size, int target) {
    if (idx == size) {
        if (target == sum) {
            tanswer += 1;
        }
        return;
    }

    func(idx + 1, numbers, sum + numbers[idx], size, target);
    func(idx + 1, numbers, sum - numbers[idx], size, target);
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    func(0, numbers, 0, numbers.size(), target);
    answer = tanswer;
    return answer;
}