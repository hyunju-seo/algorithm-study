#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<string> t(5);
vector<string> ttemp(5);
bool rotated[5];
string clockwise(string str) {
	return str[7] + str.substr(0, 7);
}
string anticlockwise(string str) {
	return str.substr(1, 7) + str[0];
}
void rotateAnticlockwise(int tnum);
void rotateClockwise (int tnum) {
	//if (tnum < 1 || tnum > 4) return;
	//ttemp[tnum] = clockwise(t[tnum]);
	rotated[tnum] = true;
	if (tnum + 1 <= 4) {
		if (!rotated[tnum + 1] && t[tnum][2] != t[tnum + 1][6])
			rotateAnticlockwise(tnum + 1);
		
	}
	if (tnum - 1 >= 1) {
		if (!rotated[tnum -1] && t[tnum ][6] != t[tnum - 1][2])
			rotateAnticlockwise(tnum - 1);
	}
	t[tnum] = clockwise(t[tnum]);



}

void rotateAnticlockwise(int tnum) {
	//ttemp[tnum] = anticlockwise(t[tnum]);
	rotated[tnum] = true;

	if ( tnum + 1 <= 4) {
		if (!rotated[tnum + 1]&&t[tnum][2] != t[tnum + 1][6])
			rotateClockwise(tnum + 1);

	}
	if (tnum - 1 >= 1) {
		if (!rotated[tnum - 1]&& t[tnum][6] != t[tnum - 1][2])
			rotateClockwise(tnum - 1);
	}
	t[tnum] = anticlockwise(t[tnum]);

}


int main() {
	cin >> t[1];
	cin >> t[2];
	cin >> t[3];
	cin >> t[4];
	
	int temp;
	cin >> temp;
	for (int i = 0; i < temp; i++) {
		int tnum, dir;
		cin >> tnum >> dir;
		memset(rotated, false, sizeof(rotated));
		if (dir == 1) {
			rotateClockwise(tnum);
		}
		else if (dir == -1) {
			rotateAnticlockwise(tnum);

		}
		//for (int j = 1; j <= 4; j++) {
		//	t[j] = ttemp[j];
		//}
	}
	int score = 0;
	//cout << t[1] << endl;
	//cout << t[2] << endl;
	//cout << t[3] << endl;
	//cout << t[4] << endl;
	if (t[1][0] == '1') score += 1;
	if (t[2][0] == '1') score += 2;
	if (t[3][0] == '1') score += 4;
	if (t[4][0] == '1') score += 8;
	cout << score << "\n";

}