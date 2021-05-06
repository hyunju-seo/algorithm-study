#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
int miro[5][5][5];

int bfs(vector<vector<vector<int>>> newmiro) {
	//cout << "bfs" << endl;

	if (newmiro[0][0][0] == 0 || newmiro[4][4][4] == 0) return -1;
	int dx[] = { 1,0,0,-1,0,0 };
	int dy[] = { 0,-1,1,0,0,0 };
	int dz[] = { 0,0,0,0,1,-1 };
	int distance[5][5][5] ;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				distance[i][j][k] = -1;
			}
		}
	}
	queue<tuple<int, int ,int>> que;
	que.push({ 0,0,0 });
	distance[0][0][0] = 0;
	while (!que.empty()) {
		int x, y, z;
		tie(x, y, z) = que.front();
		que.pop();
		if (x == 4 && y == 4 && z == 4) break;

		for (int i = 0; i < 6; i++) {
			int nextx = x + dx[i];
			int nexty = y + dy[i];
			int nextz = z + dz[i];
			if (nextx < 0 || nexty < 0 || nextz < 0 || nextx >= 5 || nexty >= 5 || nextz >= 5) continue;
			if (newmiro[nextx][nexty][nextz] == 0) continue;
			if (distance[nextx][nexty][nextz] != -1) continue;
			distance[nextx][nexty][nextz] = distance[x][y][z] + 1;
			que.push({ nextx, nexty, nextz });
		}

	}
	return distance[4][4][4];

}
int makemaze(vector<int> rot, vector<int> orders) { //125
	//cout << "makemaze" << endl;

	vector<vector<vector<int>>> newmiro;
	int orderSize = orders.size();
	for (int i = 0; i < orderSize; i++) {
		vector<vector<int>> temp(5, vector<int>(5));
		int o = orders[i];
		if (rot[i] == 1) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					temp[i][j] = miro[o][i][j];
				}
			}

		}
		else if (rot[i] == 2) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					temp[i][j] = miro[o][j][4-i];
				}
			}
		}
		else if (rot[i] == 3) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					temp[i][j] = miro[o][4 - i][4 - j];
				}
			}
		}
		else {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					temp[i][j] = miro[o][4 - j][i];
				}
			}
		}
		newmiro.push_back(temp);
	}

	return bfs(newmiro);

}
int rotationOrder(int cnt, vector<int> rot, vector<int> orders) { //1365 
	//cout << "rotattionOrder"<< cnt << endl;
	if (cnt == 5) {
		
		return makemaze(rot, orders);
	}
	int ans = 1000000;
	int ret;
	for (int i = 1; i <= 4; i++) {
		rot.push_back(i);
		ret= rotationOrder(cnt + 1, rot, orders);
		if (ret != -1) ans = min(ans, ret);
		rot.pop_back();

	}

	return ans;

}

int main() {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				cin >> miro[i][j][k];
			}
		}
	}

	vector<int> orders;
	for (int i = 0; i < 5; i++) orders.push_back(i);
	int ans = 1000000;
	while (true) {

		vector<int> rot;
		ans=min(ans, rotationOrder(0, rot, orders));
		if (!next_permutation(orders.begin(), orders.end())) break;
	}
	if (ans == 1000000) cout << -1 << "\n";
	else cout << ans << "\n";


}