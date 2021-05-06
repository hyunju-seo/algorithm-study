#include<iostream>
#include<vector>
using namespace std;
int const observ = 100;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int n, m;

void check(vector<vector<int>>& map, int x, int y, int dir) {
	int nextx = x + dx[dir];
	int nexty = y + dy[dir];
	while (true) {
		if (nextx >= n || nexty >= m || nextx < 0 || nexty < 0) break;
		if (map[nextx][nexty] == 6) break;
		if(map[nextx][nexty]==0)
			map[nextx][nexty] = observ;
		nextx += dx[dir];
		nexty += dy[dir];

	}
}


int func(vector<vector<int>> map, vector<pair<int, int>> cctv, int idx, vector<int> dirs) {
	//cout << idx << endl;
	if (idx == cctv.size()) {
		for (int i = 0; i < cctv.size(); i++) {
			int x = cctv[i].first;
			int y = cctv[i].second;
			if (map[x][y] == 1) {
				check(map, x, y, dirs[i]);
			}
			else if (map[x][y] == 2) {
				check(map, x, y, dirs[i]);
				check(map, x, y, dirs[i] + 2);
			}
			else if (map[x][y] == 3) {
				check(map, x, y, dirs[i] );
				check(map, x, y, (dirs[i] + 1) % 4 );

			}
			else if (map[x][y] == 4) {
				check(map, x, y, dirs[i]);
				check(map, x, y, (dirs[i] + 1) % 4);
				check(map, x, y, (dirs[i] + 2) % 4);
			}
			else if (map[x][y] == 5) {
				check(map, x, y, dirs[i]);
				check(map, x, y, dirs[i] + 1);
				check(map, x, y, dirs[i] + 2);
				check(map, x, y, dirs[i] + 3);
			}

		}
		int ret = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0) ret += 1; 
			}
		}
		return ret;
	}
	
	int x = cctv[idx].first;
	int y = cctv[idx].second;
	int ret = 100;
	if (map[x][y] == 1 || map[x][y] == 3 || map[x][y] == 4) {
		for (int i = 0; i < 4; i++) {
			dirs[idx] = i;
			ret= min(ret, func(map, cctv, idx + 1, dirs));

		}
	}
	else if (map[x][y] == 2) {
		dirs[idx] = 0;
		ret = min(ret, func(map, cctv, idx + 1, dirs));
		dirs[idx] = 1;
		ret= min(ret, func(map, cctv, idx + 1, dirs));

	}
	else if (map[x][y] == 5) {
		dirs[idx] = 0;
		ret= min(ret, func(map, cctv, idx + 1, dirs));

	}

	return ret;

}



int main() {
	cin >> n >> m;
	vector<vector<int>> map(n, vector<int>(m));
	vector<pair<int, int>> cctv;
	vector<int> dirs;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				cctv.push_back({ i,j });
				dirs.push_back(0);
			}
		}
	}

	cout<< func(map, cctv, 0, dirs);
}