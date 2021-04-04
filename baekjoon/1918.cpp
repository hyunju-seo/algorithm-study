#include<iostream>
#include<stack>
using namespace std;

int opGrade(char a) {
	if (a == '+') return 1;
	if (a == '-')return 1;
	if (a == '*') return 2;
	if (a == '/') return 2;
	return 0;
}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin >> str;
	stack<char> stk;
	string ans = "";
	for (auto s : str) {
		if (s >= 'A' && s <= 'Z') ans += s;
		else {
			if (s == '(') stk.push(s);
			else if (s == ')') {
				while (!stk.empty()) {
					if (stk.top() == '(') break;
					ans += stk.top();
					stk.pop();
				}
				stk.pop();
				
			}
			
			else {
				while (!stk.empty()) {
					if (opGrade(stk.top()) < opGrade(s)) break;
					ans += stk.top();
					stk.pop();
				}
				stk.push(s);
			}
		}
	}
	while (!stk.empty()) {
		ans += stk.top();
		stk.pop();
	}
	cout << ans << "\n";
}