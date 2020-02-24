//1874
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int in = 0;
	bool flag = true;
	cin >> n;
	stack<int> stk;
	vector<char> result;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		while (true) {
			if (stk.empty()) {
				in++;
				stk.push(in);
				result.push_back('+');
			}
			if (in > n) {
				flag = false;
				break;
			}


			if (stk.top() == num) {
				stk.pop();
				result.push_back('-');
				break;
			}
			else if (stk.top() > num) {
				stk.pop();
				result.push_back('-');

			}
			else {
				in++;
				stk.push(in);
				result.push_back('+');

			}
		}


	}
	if (flag) {
		for (auto r : result) {
			cout << r << '\n';
		}
	}
	else {
		cout << "NO";
	}



}