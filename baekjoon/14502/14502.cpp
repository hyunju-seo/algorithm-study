#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;
const int virus = 2;
int map[10][10];
bool visited[10][10];
vector<pair<int,int>> virus_pos;
int n, m;
vector<int>answers;
int dx[] = { 0,1,-1,0 };
int dy[] = { 1,0,0,-1 };

void bfs(int x, int y) {
	queue<pair<int, int>> que;
	visited[x][y] == true;
	que.push({ x, y });
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nextx = x + dx[i];
			int nexty = y + dy[i];
			if (nextx >= n || nexty >= m || nextx < 0 || nexty < 0) continue;
			if (map[nextx][nexty] == 0 && visited[nextx][nexty] == false) {
				visited[nextx][nexty] = true;
				que.push({ nextx,nexty });

			}
		}
	}

}


//pos자리에 있을 때, 이 자리에 wall을 세울지 말지
void buildwall(int pos, int wallnum) {
	//cout << pos<<" "<<wallnum << endl;
	//불가능한 경우

	//답인 경우
	if (wallnum == 3) {
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < m; j++) {
		//		cout << map[i][j] << " ";
		//	}cout << endl;
		//}cout << endl;
		memset(visited, false, sizeof(visited));
		for (auto v : virus_pos) {
			int x = v.first;
			int y = v.second;
			bfs(x, y);
		}
		int num=0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0 && visited[i][j] == false) num++;

			}
		}
		answers.push_back(num);
		return;
	} 
	if (pos >= n * m) return;

	int x = pos / m;
	int y = pos % m;
	if (map[x][y] == 0) {
		map[x][y] = 1;
		buildwall(pos+1, wallnum + 1);
		map[x][y] = 0;
	}
	buildwall(pos + 1, wallnum );



}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == virus) {
				virus_pos.push_back({ i,j });
			}
		}
	}
	buildwall(0, 0);
	cout << *max_element(answers.begin(), answers.end());
}