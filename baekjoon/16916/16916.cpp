//#include<iostream>
//#include<string>
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	string str, substr;
//	cin >> str;
//	cin >> substr;
//	int len = substr.length();
//	int ans = 0;
//	for (int i = 0; i < str.length(); i++) {
//		if (i + len -1 >= str.length()) break;
//		if (str.substr(i, len) == substr) {
//			ans = 1;
//			break;
//		}
//	}
//	cout << ans << "\n";
//
//
//}
#include<iostream>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str, substr;
	cin >> str;
	cin >> substr;
	int len = substr.length();
	int ans = 0;
	for (int i = 0; i < str.length(); i++) {
		
		if (i + len - 1 >= str.length()) break;
		if (str[i] != substr[0])continue;
		if (str.substr(i, len) == substr) {
			ans = 1;
			break;
		}
	}
	cout << ans << "\n";


}