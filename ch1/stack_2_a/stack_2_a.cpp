//stack���� '('�� �� -> stack�� ������� �ʰ� ������ ����
#include<iostream>
#include<string>
using namespace std;

string valid(string &s) {
	int num=0;
	for (auto ch : s) {
		if (ch == '(') {
			num++;
		}
		else if (ch == ')') {
			num--;
		}if (num < 0) {
			return "NO"; 
		}
	}if (num > 0) {
		return "NO";
	}
	return "YES";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string str;
		cin >> str;
		cout<<valid(str)<<'\n';
	}
	
}