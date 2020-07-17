#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int num[15];

int cal(int n1, int n2, int op) {
	if (op == 0) {
		return n1 + n2;
	}
	else if (op == 1) {
		return n1 - n2;
	}
	else if (op == 2) {
		return n1 * n2;
	}
	else if (op == 3) {
		return n1 / n2;
	}

}

int main() {
int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	vector<int> operators;
	for (int i = 0; i < 4; i++) {
		int op;
		cin >> op;
		for (int j = 0; j < op; j++) {
			operators.push_back(i);
		}
	}
	//최대 최소를 잘 설정하기
	//주석과 같이해서 틀림
	//long long maxans = -10000001;
	//long long minans = 10000001;
	vector<int> answers;
	do {
		long long sum = 0;

		sum = cal(num[0], num[1], operators[0]);
		for (int i = 1; i < operators.size(); i++) {
			sum = cal(sum, num[i + 1], operators[i]);
		}
		answers.push_back(sum);
		//maxans = max(sum, maxans);
		//minans = min(sum, minans);
	} while (next_permutation(operators.begin(),operators.end()));
	auto ans = minmax_element(answers.begin(), answers.end());
	cout << *ans.second << endl << *ans.first << endl;
}
