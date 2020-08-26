//9012
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	cin.ignore();
	for (int i = 0; i < T; i++) {
		string str;
		string result = "YES";
		getline(cin, str);
		stack<char> stk;
		for (auto ch : str) {
			if (ch == ')') {
				if (stk.empty()) {
					result = "NO";
					break;
				}
				else {
					stk.pop();
				}
			}
			else if (ch == '(') {
				stk.push(ch);
			}
			
		}
		if (!stk.empty()) {
			result = "NO";
		}
		cout << result<<'\n';
	}

}