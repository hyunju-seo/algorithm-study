#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	int num;
	cin >> num;
	for (int i = 0; i <= num; i++) {
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