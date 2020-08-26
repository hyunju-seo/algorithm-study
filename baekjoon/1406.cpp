//1406 ������
#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
	//�ð��ʰ�
	//�̷��� ���ڿ��� ���� ���� �ϸ� ���� �� ������ ��� ���ڵ��� �ٽ� �Űܾ��ϰ�
	//�����Ҷ��� ����������
	//���� or linked list �̿�
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//string str;   //���ڿ�
	//cin >> str;
	//int len=str.length();   // ���ڿ��� ����
	//int M;
	//cin >> M;   //�Է��� ����� ����
	//int cs=len;   //Ŀ�� ��ġ
	//char ch; 

	//for (int i = 0; i < M; i++) {
	//	cin >> ch;

	//	if (ch == 'L') {
	//		if (cs> 0) {
	//			cs--;
	//		}
	//		
	//	}
	//	else if(ch=='D'){
	//		if (cs < len) {
	//			cs++;
	//		}
	//	}
	//	else if (ch == 'B') {
	//		if (cs > 0) {
	//			cs--;
	//			str.erase(cs,1);
	//			len -= 1;
	//		}
	//	}
	//	else if(ch=='P'){
	//		string c;
	//		cin >> c;
	//		str.insert(cs,c);
	//		len += 1;
	//		cs++;
	//	}
	//}
	//cout << str;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin >> str;
	stack<char> stk;
	stack<char> answer;
	for (auto ch: str) {
		stk.push(ch);
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		char ch;
		cin >> ch;
		if (ch == 'L') {
			if (!stk.empty()) {
				answer.push(stk.top());
				stk.pop();
			}

		}
		else if (ch == 'P') {
			char extra;
			cin >> extra;
			stk.push(extra);
		}
		else if (ch == 'B') {
			if (!stk.empty()) {
				stk.pop();
			}
		}
		else if (ch == 'D') {
			if (!answer.empty()) {
				stk.push(answer.top());
				answer.pop();
			}
		}
	}
	while (!stk.empty()) {
		answer.push(stk.top());
		stk.pop();
	}
	while (!answer.empty()) {
		cout<<answer.top();
		answer.pop();
	}
	
}


