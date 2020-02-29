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
	//stk�� �� ( �� ����
	int stk=0;
	//true: ( , close: ) 
	bool open = true;
	//����� ����
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
				//stk�� �������� �������� ����� ����
				answer += stk;		
				
			}
			//����� ����
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
/*����
)�� ������ �� ������ ( �̸� laser�̴�.
)�� ������ �� ������ )�̸� ������̴�.
*/