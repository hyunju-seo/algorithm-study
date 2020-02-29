#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	getline(cin, str);
	int answer = 0;
	//stk에 들어간 ( 의 개수
	int stk=0;
	//true: ( , close: ) 
	bool open = true;
	//막대기 개수
	int stick=0;
	for (auto s : str) {
		if (s == '(') {
			open = true;
			stk++;
		}
		else if (s == ')') {
			//laser
			if (open == true) {
				stk--;
				//stk는 레이저가 지나가는 막대기 개수
				answer += stk;		
				
			}
			//막대기 생성
			else {
				stk--;
				stick++;
			}
			open = false;
		
		}
	
	}
	answer += stick;
	cout << answer;
}
/*설명
)가 나왔을 때 이전이 ( 이면 laser이다.
)가 나왔을 때 이전이 )이면 막대기이다.
*/