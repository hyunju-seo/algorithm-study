// https://www.acmicpc.net/problem/6603
#include<iostream>
#include<vector>
#define lnum 6
using namespace std;

vector<int> d;
vector<int> answer;
int n; //집합 s에 포함되는 수의 개수

//현재 채워진 자릿수와 가장 마지막에 채워진 수가 주어졌을 때, 다음 수를 고르는 함수
void lotto(int last, int num) {  //last : 가장 마지막 수의 index, num: 현재 채워진 자릿수
	
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
		lotto(i, num+1);  //num++말고 num+1이라고 해야지 먹힘
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

