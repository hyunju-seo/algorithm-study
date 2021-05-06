//중복조합
//n개의 수 중 k개를 골라라

#include<iostream>
#include<vector>
using namespace std;
int n = 5;
int k = 3;
void func(int idx, int cnt, vector<int> selected) {
	if (cnt == k) {
		for (auto s : selected) cout << s << " ";
		cout << "\n";
		return;
	}
	
	for (int i = idx; i <= n; i++) {
		selected.push_back(i);
		func(i, cnt + 1, selected);
		selected.pop_back();
	}
	return;
}


int main() {
	vector<int> nums;
	for (int i = 1; i < n; i++) nums.push_back(i);
	vector<int> selected;
	func(1, 0, selected);
}
