#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	stack<int> stk;
	vector<int> answer(N,-1);
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		
		if (stk.empty()) {
			stk.push(i);
		} 
		
		while (!stk.empty()&&A[i] > A[stk.top()]) {
			answer[stk.top()] = A[i];
			stk.pop();
		}
		stk.push(i);

		
	}
	for (auto v : answer) {
		cout << v << ' ';
	}
	cout << '\n';
}