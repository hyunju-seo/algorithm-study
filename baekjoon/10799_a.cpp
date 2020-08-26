#include<iostream>
#include<stack>
#include<string>

//stack에 index를 집어 넣고 , 만약 ( 과 )의 index가 1차이면 laser

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin >> str;
	stack<int> stk;   //stk를 char이라고 해서 백준에서 틀림
	int answer = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			stk.push(i);
		}
		else {
			//laser
			if (stk.top() + 1 == i) {
				stk.pop();
				answer += stk.size();
			}
			//막대기
			else {
				stk.pop();
				answer+=1;  //막대기에 laser가 3번 지나가면 4조각 이므로

			}
		}
	}
	cout << answer;
	return 0;
}