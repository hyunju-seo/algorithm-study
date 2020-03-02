#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	vector<int> vec_num(n);
	stack<int> stk;
	vector<int>answer(n);
	for (int i = 0; i < n; i++) {
		int in;
		cin >> in;
		for (int j = 0; j < i; j++) {
			if (vec[j] == in) {
				vec_num[j] += 1;
				vec_num[i] = vec[j];
			}
		
		}

	}
	
	stk.push(0);
	for (int i = 1; i < n; i++) {
			int top = stk.top();
			if (vec_num[top] < vec_num[i]&&vec_num[top]!=vec_num[i]) {
				while (!stk.empty()) {
					stk.pop();
					answer[top] = vec[i];
				}
			}
			else {
				stk.push(i);


			}
			cout << 'p';
		
	}

	for (auto a : answer) {
		cout << a;
	
	}
}