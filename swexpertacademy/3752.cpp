//https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=4&problemLevel=5&contestProbId=AWHPkqBqAEsDFAUn&categoryId=AWHPkqBqAEsDFAUn&categoryType=CODE&problemTitle=&orderBy=SUBMIT_COUNT&selectCodeLang=CCPP&select-1=5&pageSize=10&pageIndex=1

#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<int> vec;
int answer;
bool inserted[10001];
vector<int> answers;
void func(int idx) {
	if (idx >= vec.size()) {
		answer = answers.size();
		return;
	}

	int len = answers.size();
	for (int i = 0; i < len;i++) {
		int a = answers[i]+vec[idx];
		if (inserted[a])continue;
		inserted[a] = true;
		answers.push_back(a);
	}
	func(idx + 1);

}

int main(int argc, char** argv) {
	int t;
	cin >> t;
	for (int T = 1; T <= t; T++) {
		int n;
		answer = 0;
		cin >> n;
		vec.clear();
		answers.clear();
		for (int i = 0; i < 10001; i++) {
			inserted[i] = false;
		}
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			vec.push_back(a);
		}
		inserted[0] = true;
		answers.push_back(0);
		func(0);

		cout << "#" << T << " " << answer << "\n";
	}

	return 0;
}