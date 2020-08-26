//answer°ú °°À½

#include<iostream>
#include<string>
#include<stack>
using namespace std;
void pop(stack<char>& stk) {
	while (!stk.empty()) {
		cout << stk.top();
		stk.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	getline(cin, str);
	bool tag = false;
	stack<char> stk;
	for (auto s : str) {
		if (s == '<') {
			pop(stk);
			tag = true;
			cout << s;
		}
		else if (s == '>') {
			tag = false;
			cout << s;
		}
		else if (tag == true) {
			cout << s;
		}
		else if (s == ' ') {
			pop(stk);
			cout << ' ';
			
		}
		else {
			stk.push(s);
		}

	}
	pop(stk);

}