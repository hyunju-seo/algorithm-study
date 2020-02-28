#include<iostream>
#include<list>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	list<char> result;
	string str;
	cin >> str;
	for (auto s : str) {
		result.push_back(s);
	}
	int M;
	cin >> M;
	list<char>::iterator cursor = result.end();
	for (int i = 0; i < M; i++) {
		char ch;
		cin >> ch;
		if (ch == 'L') {
			if (cursor!=result.begin()) {
				cursor--;

			}
		}
		else if (ch == 'D') {
			if (cursor!=result.end()) {
				cursor++;

			}
				}
		else if (ch == 'P') {
			char x;
			cin >> x;
		
			result.insert(cursor, x);
			//cursor++;  �̰� �ϸ� �ȵ� => list�� linked list��. {1,2,3} ���� *it�� 3�̾��ٸ� , insert(it,100) �� �� �Ŀ��� *it�� 3�̴�
					
		}
		else if (ch == 'B') {
			if (cursor!=result.begin()) {
				cursor--;
				//result.erase(cursor);  �̷��� �ϸ� cursor(iterator)�� ����Ű�� ���� �������� cursor�� �������. 
				cursor = result.erase(cursor);

			}
		}
	
	
	}
	for (auto l : result) {
		cout << l;
	}

}