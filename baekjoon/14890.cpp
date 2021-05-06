#include<iostream>

using namespace std;
int map[101][101];
bool ramp[101][101];
int main() {
	int n, l;
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	int xroad = 0;
	for (int i = 0; i < n; i++) {
		int samecnt = 1;
		for (int j = 0; j < n-1; j++) {
			if (map[i][j] == map[i][j + 1]) samecnt += 1;
			else {
				if (map[i][j] == map[i][j + 1] + 1) {
					bool br = false;

					for (int k = j + 1; k <= j + l; k++) {
						if (map[i][j] == map[i][k]+1) {
							ramp[i][k] = true;
						}
						else {
							xroad += 1;
							br = true;
							break;
						}

					}
					if (br) break;
				}
				else if (map[i][j] + 1 == map[i][j + 1]) {
					if (samecnt < l) {
						xroad += 1;
						break;

					}
					bool br = false;
					for (int k = j ; k > j - l; k--) {
						if(ramp[i][k]) {
							xroad += 1;
							br = true;
							break;
						}
					}
					if (br) break;

					for (int k = j; k > j - l; k--) 
						ramp[i][k] = true;
					
				
				}
				else {
					xroad += 1;
					break;
				}
				samecnt = 1;
			}
		}

	}
	//cout << xroad << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ramp[i][j] = false;
		}
	}

	for (int j = 0; j < n; j++) {
		int samecnt = 1;
		for (int i = 0; i < n-1; i++) {
			if (map[i][j] == map[i+1][j]) samecnt += 1;
			else {
				if (map[i][j] == map[i + 1][j] + 1) {
					bool br = false;

					for (int k = i + 1; k <= i+ l; k++) {
						if (map[i][j] == map[k][j] + 1) {
							ramp[k][j] = true;
						}
						else {
							xroad += 1;
							br = true;
							//cout << "nop1" << j << endl;
							break;
						}

					}
					if (br) break;
				}
				else if (map[i][j] + 1 == map[i + 1][j]) {
					if (samecnt < l) {
						xroad += 1;
						//cout << "nop2" << j << endl;

						break;

					}
					bool br = false;
					for (int k = i; k > i - l; k--) {
						//cout <<"  " << i  << k <<"  "<< j << endl;
						if (ramp[k][j]) {
							xroad += 1;
							br = true;
							//cout << "nop3" << j << endl;

							break;
						}
					}
					if (br) break;

					for (int k = i; k > i - l; k--) 
						ramp[k][j] = true;


				}
				else {
					xroad += 1;
					//cout << "nop4" << j << endl;

					break;
				}
				samecnt = 1;
			}
		}

	}


	cout << 2 * n - xroad << "\n";
}