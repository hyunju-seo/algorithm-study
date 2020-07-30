#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>

#include<vector>
using namespace std;
bool arr[30];
int main() {
	int n;
	cin >> n;
	vector<string> slist;
	//slist에 string으로 문자열을 입력받음
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		slist.push_back(str);
	}
	//알파벳 종류의 개수를 셈
	int alphabetnum=0;
	vector<char> alphabets;
	for (auto s : slist) {
		for (auto ch : s) {
			if (arr[ch - 'A'] == false) {
				arr[ch - 'A'] = true;
				alphabetnum++;
				alphabets.push_back(ch);
			}

		}
	}

	int ans = -1;
	vector<int> permu;
//permu에 9~0까지 집어넣음
	for (int i = 0; i < alphabetnum; i++) {
		permu.push_back(9 - i);
	}	

	do {
		char alpha[256];

		for (int i = 0; i < alphabets.size(); i++) {
			alpha[alphabets[i] - 'A'] = permu[i];
		}
	//알파벳의 합 확인
		int sum = 0;
		
		for (auto s : slist) {
			int mul = 1;
			for (int i = s.size()-1; i >=0;i--) {
				sum+=alpha[s[i] - 'A'] * mul;
				mul *= 10;

			}
		}
		ans = max(ans, sum);

	} while (prev_permutation(permu.begin(), permu.end()));
	cout << ans;
}
