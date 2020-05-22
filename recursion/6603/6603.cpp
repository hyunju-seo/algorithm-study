// https://www.acmicpc.net/problem/6603
#include<iostream>
#include<vector>
#define lnum 6
using namespace std;

vector<int> d;
vector<int> answer;
int n; //���� s�� ���ԵǴ� ���� ����

//���� ä���� �ڸ����� ���� �������� ä���� ���� �־����� ��, ���� ���� ���� �Լ�
void lotto(int last, int num) {  //last : ���� ������ ���� index, num: ���� ä���� �ڸ���
	
	if (num == lnum) {
		for (int i = 0; i < lnum; i++) {
			cout << answer[i]<<" ";
		}
		cout << "\n";
		return;
	}
	if (last == d[n - 1]) {
		return;
	}
	for (int i = last + 1; i < n; i++) {
		answer.push_back(d[i]);
		//for (int no = 0; no < answer.size(); no++) {
		//	cout << answer[no] << ", ";
		//}
		//cout << endl;
		lotto(i, num+1);  //num++���� num+1�̶�� �ؾ��� ����
		answer.pop_back();
	}
}

int main() {
	while (true) {
		cin >> n;
		d.clear();
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			int p;
			cin >> p;
			d.push_back(p);
		}
		lotto(-1, 0);
		cout << "\n";
	}
}

