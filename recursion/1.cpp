//������ 148p
#include<iostream>
#include<vector>
using namespace std;

//picked ���ݱ��� �� ����, toPick ������ �� ������ ��

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
	else smallest=picked.back() + 1;  //�� �� �ִ� ���� ���� ����
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