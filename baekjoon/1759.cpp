#include<iostream>
#include<vector>
#include<algorithm>
int l, c;
using namespace std;
vector<char> word;
vector<char> answer;

//암호가 될 수 있는지 체크
//모음 수 1개 이상, 자음 수 2개 이상
bool check() {
	int vowel = 0;
	int consonant = 0;
	for (auto alpha : answer) {
		if (alpha == 'a' || alpha == 'e' || alpha == 'i' || alpha == 'o' || alpha == 'u') {
			vowel++;
		}
		else consonant++;


	}
	return consonant >= 2 && vowel >= 1;
}

//방법 1 이전 문자가 입력되었을때 가능한 문자구하기
void code(int prev, int remains) {
	//암호가 완성된 경우
	if (remains == 0 && check()) {
		for (auto alpha : answer) {
			cout << alpha;
		}
		cout << endl;
		return;
	}
	//암호가 완성될 수 없는 경우 ( 남은 알파벳이 없는데 remains가 0이 아님)
	if (prev == c - 1) {
		return;
	}
	for (int i = prev + 1; i < c; i++) {
		answer.push_back(word[i]);
		code(i, remains - 1);
		answer.pop_back();

	}
}

//방법 2 현재 문자index 가 주어질때 이게 암호에 포함될지 말지를 정하는 코드
void now_code(int now, int remains) {
	//암호가 만들어진 경우
	if (remains == 0 && check()) {
		for (auto alpha : answer) {
			cout << alpha;
		}
		cout << endl;
		return;
	}
	//아예 불가능한 경우
	if (now >= c) {
		return;
	}
	//포함될 경우 (이게 먼저 와야 오름차순)
	answer.push_back(word[now]);
	now_code(now + 1, remains - 1);
	answer.pop_back();
	//현재 문자가 포함 안될 경우
	now_code(now + 1, remains);


}

int main() {
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		char w;
		cin >> w;
		word.push_back(w);
	}
	sort(word.begin(), word.end());
	//code(-1, l);
	now_code(0, l);
}