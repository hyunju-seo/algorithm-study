//n개 중 k개를 뽑아라
//재귀


#include<iostream>
#include<vector>
using namespace std;
vector<int> nums;
int n = 5;
int k = 3;
int funcCount = 0;
void func(int idx, int cnt, vector<int> selected) { //가장 마지막으로 idx번 인덱스를 뽑았을 때, 다음에 뽑아야되는 수
	funcCount += 1;
	if (cnt == k) {
		for (auto s : selected) cout << s << " ";
		cout << "\n";
		return;
	}
	for (int i = idx + 1; i <= n; i++) {
		selected.push_back(i);
		func(i, cnt + 1, selected);
		selected.pop_back();
	}
	return;


}

int func2Count = 0;

void func2(int idx, int cnt, vector<int> selected) { //현재 idx를 뽑을지말지 정해라
	func2Count += 1;
	if (cnt == k) {
		for (auto s : selected) cout << s << " ";
		cout << "\n";
		return;
	}
	if (idx > n) return;
	func2(idx + 1, cnt, selected);
	selected.push_back(idx);
	func2(idx + 1, cnt + 1, selected);
}
int main() {
	for (int i = 1; i <= n; i++) {
		nums.push_back(i);
	}
	vector<int> selected;
	func(0, 0, selected);
	cout << funcCount << endl;
	
/*	1 2 3
	1 2 4
	1 2 5
	1 3 4
	1 3 5
	1 4 5
	2 3 4
	2 3 5
	2 4 5
	3 4 5
	26 */

	cout << endl;
	cout << endl;

	func2(1, 0, selected);
	cout << func2Count << endl;

	/*
	3 4 5
	2 4 5
	2 3 5
	2 3 4
	1 4 5
	1 3 5
	1 3 4
	1 2 5
	1 2 4
	1 2 3
	51	
	*/


}
