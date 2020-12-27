#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct Member {
	int idx;
	int age;
	string name;

};
bool compare(const Member& m, const Member& m2) {
	if (m.age == m2.age) {
		return m.idx < m2.idx;
	}
	else return m.age < m2.age;
}
bool compare2(const pair<int, string> &m, const pair<int, string> &m2) {
	return m.first < m2.first;

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	
	//vector<Member> mem(n);
	//
	//for (int i = 0; i < n; i++) {
	//	mem[i].idx = i;
	//	cin >> mem[i].age >> mem[i].name;
	//}
	
	//sort(mem.begin(), mem.end(), compare);
	vector < pair<int, string>> mem2;
	for (int i = 0; i < n; i++) {
		int a;
		string na;
		cin >> a >> na;
		mem2.push_back(make_pair( a,na ));
	
	}

	stable_sort(mem2.begin(), mem2.end(), compare2);
	for (auto m : mem2) {
		cout << m.first << " " << m.second << "\n";

	}

}