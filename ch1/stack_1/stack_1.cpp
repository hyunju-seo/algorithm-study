#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	int num;
	cin >> num;
	for (int i = 0; i <= num; i++) {
		string str;
		stack<char> stk;
		getline(cin, str);
		while (str.size() > 0) {

			const char* ch = &str.at(str.size()-1);
			if (ch != " ") {
				stk.push(str[str.size() - 1]);
				str.pop_back();

			}
			else {
				while (stk.empty()) {
					cout << stk.top();
					stk.pop();
				}
					
			}
		
		}
	}

}