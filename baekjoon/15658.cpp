#include<iostream>
#include<vector>
#include<algorithm>

int n;

using namespace std;

int input[20];
int op_input[4];
int calculate(int idx, int result, int op) {
	if (op == 1) {
		return result + input[idx + 1];
	}
	else if (op == 2) {
		return result - input[idx + 1];
	}
	else if (op == 3) {
		return result * input[idx + 1];
	}
	else if (op == 4) {
		return result / input[idx + 1];
	}

}
vector<int> answers;
void calc(int idx, int result, int plus, int minus, int multi, int divi) {
	if (idx == n - 1) {
		answers.push_back(result);
		return;
	}
	 if (plus > 0) {
		calc(idx + 1, calculate(idx, result, 1), plus-1,minus, multi, divi);
	}
	 if (minus > 0) {
		calc(idx + 1, calculate(idx, result, 2), plus , minus-1 , multi, divi);
	}
	 if (multi > 0) {
		calc(idx + 1, calculate(idx, result, 3), plus , minus, multi-1 , divi);
	}
	if (divi > 0) {
		calc(idx + 1, calculate(idx, result, 4), plus , minus, multi, divi-1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op_input[i];
	}
	calc(0, input[0], op_input[0], op_input[1], op_input[2], op_input[3]);
	sort(answers.begin(), answers.end());
	cout << answers.back() << "\n" << answers.front() << "\n";
}