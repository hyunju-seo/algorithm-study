#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;
struct meetingtime {
	int start;
	int end;

};
vector<meetingtime> starttime;

bool compare(meetingtime m1, meetingtime m2) {
	if (m1.end == m2.end) {
		return m1.start < m2.start;
	}return m1.end < m2.end;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		meetingtime m;
		cin >> m.start >> m.end;
		starttime.push_back(m);
	}


	sort(starttime.begin(), starttime.end(),compare);
	int answer = 0;
	int poss = 0;
	for (auto s: starttime) {
		if (s.start < poss) continue;
		poss = s.end;
		answer += 1;
		
	}

	
	cout << answer << "\n";
}