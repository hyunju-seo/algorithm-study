#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int, int >> vec;
bool compare(const pair<int, int> &p1, const pair<int, int> &p2) {
	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}
	else {
		return p1.second < p2.second;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back({ a,b });
	}

	sort(vec.begin(), vec.end(), compare);
	for (auto v : vec) {
		cout << v.first << " " << v.second << "\n";
	}
}