#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int num;
	cin >> num;
	cin.ignore();
	for (int i = 0; i < num; i++) {
		string str;
		stack<char> stk;
		getline(cin, str);
		str += '\n';
		for (auto ch : str) {
			if (ch == ' ' || ch == '\n') {
				while (!stk.empty()) {
					cout << stk.top();
					stk.pop();
				}
				cout << ch;
			}
			else {
				stk.push(ch);
			}
		}
	}
}