#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string answer;
	//stack에 마지막으로 들어간 숫자
	int m = 0;
	stack<int> stk;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num > m) {
			while (num > m) {
				m++;
				stk.push(m);
				answer+='+';
			}
			stk.pop();
			answer += '-';

		}
		else {
			flag = false;
			if (!stk.empty()) {
				int top = stk.top();
				stk.pop();
				answer += '-';
				if (num == top) {
					flag = true;
				}
			}

			if (flag == false) {
				cout << "NO";
				return 0;
			}

		}
	}
	for (auto e : answer) {
		cout << e << '\n';
	}

}