//종만북 148p
#include<iostream>
#include<vector>
using namespace std;

//picked 지금까지 고른 원소, toPick 앞으로 고를 원소의 수

void go(vector<int>&picked,int n, int toPick) {
	if (toPick == 0) {
		for (int i = 0; i < 4; i++) {
			cout << picked[i]<<" ";
		}
		cout << "\n";
		return;
	}
	int smallest;

	if (picked.empty()) smallest = 0;
	else smallest=picked.back() + 1;  //고를 수 있는 가장 작은 원소
	for (int next = smallest; next < n; next++) {
		picked.push_back(next);
		go(picked, n, toPick - 1);
		picked.pop_back();
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> picked;
	go(picked, n, 4);

}