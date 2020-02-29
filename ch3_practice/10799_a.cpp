#include<iostream>
#include<stack>
#include<string>

//stack�� index�� ���� �ְ� , ���� ( �� )�� index�� 1���̸� laser

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin >> str;
	stack<int> stk;   //stk�� char�̶�� �ؼ� ���ؿ��� Ʋ��
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
			//�����
			else {
				stk.pop();
				answer+=1;  //����⿡ laser�� 3�� �������� 4���� �̹Ƿ�

			}
		}
	}
	cout << answer;
	return 0;
}