//2권 831p 고대어 사전
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
vector<int> vec[26];
int alpha[26][26];
bool visited[26];
vector<int> answer;
void dfs(int al) {
	visited[al] = true;
	for (int i = 0; i < vec[al].size(); i++) {
		if (visited[vec[al][i]]) continue;
		dfs(vec[al][i]);
	}
	answer.push_back(al);
	//char tt = al + 'a';
	//cout << tt << endl;
}
int main() {
	int tc;
	cin >> tc;
	while (tc != 0) {
		tc -= 1;
		int n;
		cin >> n;
		answer.clear();
		memset(visited, 0, sizeof(visited));
		memset(alpha, 0, sizeof(alpha));
		for (int i = 0; i < 26; i++) vec[i].clear();
		vector<string> str;
		for (int i = 0; i < n; i++) {
			string tmp;
			cin >> tmp;
			str.push_back(tmp);
		}
		for (int i = 1; i < n; i++) {
			int j = i - 1;
			int len = min(str[i].size(), str[j].size());
			for (int t = 0; t < len; t++) {
				if (str[i][t] != str[j][t]) {
					
					vec[str[i][t]-'a'].push_back(str[j][t]-'a');
					alpha[str[j][t] - 'a'][str[i][t] - 'a'] = 1;
					break;
				}
			}
		}
		for (int i = 0; i < 26; i++) {
			if (visited[i]) continue;
			dfs(i);
		}
		bool ans = true;
		for (int i = 0; i < answer.size(); i++) {
			for (int j = i+1; j < answer.size(); j++) {
				int prev = answer[i];
				int aft = answer[j];
				if (alpha[aft][prev]==1) {
			
					ans = false;
					break;
				}
			}
		}
		string ret = "";
		for (int i = 0; i < answer.size(); i++) {
			char ta = 'a' + answer[i];
			ret += ta;
		}
		//cout << ret << endl;

		for (int i = 0; i < 26; i++) {
			if (visited[i]) continue;
			char ta = 'a' + i;
			ret += ta;

		}
		if (!ans) cout << "INVALID HYPOTHESIS"<<"\n";
		else cout << ret<<"\n";
		//cout << ret << endl;
	}
}
