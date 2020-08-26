//Á¾¸¸ºÏ 160
/*
# . . . . . #
# . . . . . #
# # . . # # #

*/
#include<iostream>                   
#include<vector>
using namespace std;
//int direction[4][2][2] = { {{0,-1} , {1,0}},{{-1,0} ,{0,-1}} ,{{-1,0},{0,1} },{{0,1},{1,0}}, };
int direction[4][2][2] = { {{0,-1} , {1,0}},{{0,-1} ,{-1,-1}} ,{{1,0},{1,-  1} },{{0,-1},{1,-1}}, };

int go(int taken[20][20], int h, int w, int w_num) {
	if (w_num == 0) return 1;
	int ret = 0; 
	int x=0, y=0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (taken[j][i] == 1) {
				x = j;
				y = i;
				cout<<"x,y " << x << " " << y << endl;
				goto EXIT;
			}
		}
	}
EXIT:

	for (int i = 0; i < 4; i++) {

		int x1 = x + direction[i][0][0];
		int y1 = y + direction[i][0][1];
		//cout << "x + direction " << x << " " << direction[i][0][0];
		//cout << "y + direction " << y << " " << direction[i][0][1];
		//cout << "x + direction " << x << " " << direction[i][1][0];
		//cout << "y + direction " << y << " " << direction[i][1][1];
		int x2 = x + direction[i][1][0];
		int y2 = y + direction[i][1][1];
		cout << "x1,y1 " << x1 << " " << y1 << endl;
		cout << "x2,y2 " << x2 << " " << y2 << endl;

		if (x1<0 || x1>=w || y1<0 || y1>=h || x2<0 || x2>=w || y2<0 || y2>=h) continue;
		if (taken[x1][y1] == 1 && taken[x2][y2] == 1) {
			cout << " hey " << endl;
			taken[x1][y1] = taken[x2][y2]=taken[x][y] =0;
			ret += go(taken,h,w,w_num-2);
			taken[x1][y1] = taken[x2][y2]= taken[x][y] = 1;

		}
	}
	return ret;
}

int main() {
	int c;
	cin >> c;
	while (c != 0) {
		c--;
		int h, w;
		cin >> h >> w;
		int taken[20][20] ;
		int w_num=0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				char a;
				cin >> a;
				if (a == '#') {
					taken[j][i] = 0;

				}
				else if (a == '.') {
					taken[j][i] = 1;
					w_num++;

				}
			}
		}
		if (w_num % 3 == 0) {
			//cout << "gogogo" << endl;
			cout << go(taken, h, w, w_num) << "\n";

		}
		else {
			cout << 0<<"\n";
		}

	}
}