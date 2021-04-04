#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct seat {
	int startTime;
	int endTime;
	bool done;
};

bool compare(seat a, seat b) {
	if (a.endTime == b.endTime) return a.startTime <= b.startTime;
	return a.endTime <= b.endTime;
}
int nextSeat(vector<seat>& vec,int seatEnd) {
	for (auto& v : vec) {
		if (v.done) continue;

		if (v.startTime >= seatEnd) {
			v.done = true;
			return v.endTime;
		}

	}
	return -1;

}
int main() {
	//vector<int> s= { 0, 6, 3, 1, 1, 2 };
	//vector<int> e= { 3, 7, 10, 5, 9, 8 };
	/*vector<int> s = {845, 26921, 15116, 1694, 43588};
	vector<int> e = {64754, 32669, 57396, 8835, 50160};*/
	/*vector<int> s = { 30140, 23679, 17663, 8492, 9777, 17803, 55388, 7420, 23107, 37469 };
	vector<int> e = { 55374, 33664, 43614, 12763, 85637, 58156, 79170, 60252, 52676, 48022 };*/
	//vector<int> s = { 26656, 30333, 62305, 9449, 3437, 11464, 24600, 44473, 2676 };
	//vector<int> e = { 27965, 58770, 73192, 80577, 64075, 46143, 57539, 79925, 59944};
	//vector<int> s = {56620, 13173, 45847, 25812, 51664, 292};
	//vector<int> e = { 76484, 47717, 52486, 46902, 64451, 56529 };
	vector<int> s = { 1, 2, 3, 4, 5};
	vector<int> e = {2, 3, 4, 5, 6 };
	if (s.size() == 0) {
		cout << 0 << endl;
		return 0;
	}
	if (s.size() == 1) {
		cout << 1 << endl;
		return 0;
	}
	vector<seat> vec;
	for (int i = 0; i < s.size(); i++) {
		vec.push_back({ s[i],e[i], false });
	}
	sort(vec.begin(), vec.end(), compare);
	vec[0].done = true;
	vec[1].done = true;
	int seatAend=vec[0].endTime;
	int seatBend = vec[0].endTime;
	int ans = 2;
	while (true) {
		if (seatAend == -1 ) break;
		if (seatBend == -1) break;
		seatAend = nextSeat(vec,seatAend);
		seatBend = nextSeat(vec, seatBend);

		if (seatAend != -1) ans += 1;
		if (seatBend != -1) ans += 1;

	}
	cout << ans << endl;
	
	return 0;

}