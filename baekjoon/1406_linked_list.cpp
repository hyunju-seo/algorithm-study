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
			//cursor++;  이걸 하면 안돼 => list는 linked list다. {1,2,3} 에서 *it가 3이었다면 , insert(it,100) 을 한 후에도 *it는 3이다
					
		}
		else if (ch == 'B') {
			if (cursor!=result.begin()) {
				cursor--;
				//result.erase(cursor);  이렇게 하면 cursor(iterator)가 가리키는 값이 지워지고 cursor도 사라진다. 
				cursor = result.erase(cursor);

			}
		}
	
	
	}
	for (auto l : result) {
		cout << l;
	}

}