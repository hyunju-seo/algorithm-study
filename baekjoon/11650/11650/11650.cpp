//#include<iostream>
//#include<vector>
//#include<algorithm>
////pair �� �̹� �� ���� �����ϴ� ����� �����Ǿ� �����Ƿ� �׳� ����ϸ� ��
//using namespace std;
//vector<pair<int, int>> inp;
//bool compare(pair<int, int> a, pair<int, int> b) {
//	if (a.first == b.first) {
//		return a.second < b.second;
//	}
//	else {
//		return a.first < b.first;
//	}
//}
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int a, b;
//		cin >> a >> b;
//		inp.push_back(make_pair( a,b ));
//	}
//	
//
//	sort(inp.begin(), inp.end());
//	for (auto temp : inp) {
//		cout << temp.first<<" " << temp.second<<"\n";
//	}
//
//}

//pair ���
#include<iostream>
#include<vector>
#include<algorithm>
//pair �� �̹� �� ���� �����ϴ� ����� �����Ǿ� �����Ƿ� �׳� ����ϸ� ��
using namespace std;
vector<pair<int, int>> inp;
bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		inp.push_back(make_pair(a, b));
	}


	sort(inp.begin(), inp.end());
	for (auto temp : inp) {
		cout << temp.first << " " << temp.second << "\n";
	}

}
