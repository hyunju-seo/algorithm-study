#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
bool icd[1000001];
int main() {

	string str, bomb;
	cin >> str >> bomb;
	memset(icd, true, sizeof(icd));
	int strSize = str.size();
	stack<pair<int, int>> s;
	if (bomb.size() == 1) {
		for (int i = 0; i < strSize; i++) {
			if (str[i] == bomb[0])icd[i] = false;
		}
	}
	else {
		for (int i = 0; i < strSize; i++) {

			if (bomb[0] == str[i]) {
				s.push({ i, 0 });
			}
			else if (!s.empty()) {
				auto p = s.top();
				//만약 stack에 넣어야할 차례라면
				if (str[i] == bomb[p.second + 1]) {
					s.push({i,p.second + 1});
					if (p.second + 1 == bomb.size() - 1) {
						for (int t = 0; t < bomb.size(); t++) {
							icd[s.top().first] = false;
							s.pop();
						}
					}
				}
				else {
					while (!s.empty()) {
						s.pop();
					}
				}
			}
		}
	}

	string ans = "";
	for (int i = 0; i < strSize; i++) {
		if (icd[i]) ans += str[i];
	}
	if (ans.size() == 0) cout << "FRULA" << endl;
	else cout << ans << endl;
}

