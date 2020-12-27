//operator 오버로딩
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct pos
{
	int x;
	int y;
	bool operator < (const pos &p){
		if (x == p.x) {
			return y < p.y;
		}
		else return x < p.x;
	}
};
vector<pos> arr;


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tx, ty;
		cin >> tx >> ty;
		arr.push_back({ tx,ty });
	}
	sort(arr.begin(), arr.end());
	for (auto a : arr) {
		cout << a.x << " " << a.y << "\n";
	}


}
////pair 사용
//#include<iostream>
//#include<vector>
//#include<algorithm>
////pair 은 이미 두 수를 정렬하는 기능이 구현되어 있으므로 그냥 사용하면 됨
//using namespace std;
//vector<pair<int, int>> inp;
//
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int a, b;
//		cin >> a >> b;
//		inp.push_back(make_pair(a, b));
//	}
//
//
//	sort(inp.begin(), inp.end());
//	for (auto temp : inp) {
//		cout << temp.first << " " << temp.second << "\n";
//	}
//
//}

////compare 함수 사용
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//struct pos
//{
//	int x;
//	int y;
//};
//vector<pos> arr;
//bool comp(pos& t, pos& z) {
//	if (t.x == z.x) {
//		return t.y < z.y;
//	}
//	else {
//		return t.x < z.x;
//	}
//}
//
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int tx, ty;
//		cin >> tx >> ty;
//		arr.push_back({ tx,ty });
//	}
//	sort(arr.begin(), arr.end(), comp);
//	for (auto a : arr) {
//		cout << a.x << " " << a.y<<"\n";
//	}
//
//
//}

