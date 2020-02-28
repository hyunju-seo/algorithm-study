//1406 에디터
#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
	//시간초과
	//이렇게 문자열을 통해 구현 하면 삭제 할 때마다 모든 문자들을 다시 옮겨야하고
	//삽입할때도 마찬가지다
	//스택 or linked list 이용
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//string str;   //문자열
	//cin >> str;
	//int len=str.length();   // 문자열의 길이
	//int M;
	//cin >> M;   //입력할 명령의 길이
	//int cs=len;   //커서 위치
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


