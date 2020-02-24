#include<iostream>
#include<vector>
#include<string>
using namespace std;
//9093
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int num;
	cin >> num;
	cin.ignore();
	for (int i = 0; i < num; i++) {
		vector<char> stk;
		string str;
		getline(cin, str);

		for (char ch : str) {
			if (ch != ' ') {
				stk.push_back(ch);
			}
			else{
				while (!stk.empty()) {
					cout << stk.back();
					stk.pop_back();
				}
				cout << " ";
			}
		}
		while (!stk.empty()) {
			cout << stk.back();
			stk.pop_back();
		}
		cout << "\n";
	}
}