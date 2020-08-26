#include<iostream>
#include<vector>
#include<algorithm>
int l, c;
using namespace std;
vector<char> word;
vector<char> answer;

//��ȣ�� �� �� �ִ��� üũ
//���� �� 1�� �̻�, ���� �� 2�� �̻�
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

//��� 1 ���� ���ڰ� �ԷµǾ����� ������ ���ڱ��ϱ�
void code(int prev, int remains) {
	//��ȣ�� �ϼ��� ���
	if (remains == 0 && check()) {
		for (auto alpha : answer) {
			cout << alpha;
		}
		cout << endl;
		return;
	}
	//��ȣ�� �ϼ��� �� ���� ��� ( ���� ���ĺ��� ���µ� remains�� 0�� �ƴ�)
	if (prev == c - 1) {
		return;
	}
	for (int i = prev + 1; i < c; i++) {
		answer.push_back(word[i]);
		code(i, remains - 1);
		answer.pop_back();

	}
}

//��� 2 ���� ����index �� �־����� �̰� ��ȣ�� ���Ե��� ������ ���ϴ� �ڵ�
void now_code(int now, int remains) {
	//��ȣ�� ������� ���
	if (remains == 0 && check()) {
		for (auto alpha : answer) {
			cout << alpha;
		}
		cout << endl;
		return;
	}
	//�ƿ� �Ұ����� ���
	if (now >= c) {
		return;
	}
	//���Ե� ��� (�̰� ���� �;� ��������)
	answer.push_back(word[now]);
	now_code(now + 1, remains - 1);
	answer.pop_back();
	//���� ���ڰ� ���� �ȵ� ���
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