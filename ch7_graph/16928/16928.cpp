#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int ladders[105];
int snakes[105];
vector<int> answers;


//1에서 idx까지 오는데 걸리는 횟수 num
void move(int idx, int num) {
	if (idx > 100) return;
	if (idx == 100) {
		answers.push_back(num);
		return;
	}
	for (int i = 1; i <= 6; i++) {
		if (ladders[i + idx] !=0) {
			move(ladders[i + idx], num + 1);
		}
		else if (snakes[i + idx] != 0) {
			move(snakes[i + idx], num + 1);
		}
		else {
			 move(i + idx, num + 1);

		}
		

	}

}
//i에서 100까지 가는데 던지는 최소 주사위 횟수

int cache[103];

//i에서 100까지 가는데 던지는 최소 주사위 횟수
int move2(int idx) {
	if (idx > 100) return -1;

	cout << idx << endl;
	if (idx == 100) return 0;
	if (cache[idx] != 0) return cache[idx];
	vector<int> candi;
	for (int i = 1; i <= 6; i++) {
		int temp;
		if (ladders[i + idx] != 0) {
			temp=move2(ladders[i + idx]);
		}
		else if (snakes[i + idx] != 0) {
			temp=move2(snakes[i + idx]);
		}
		else {
			temp=move2(i + idx);

		}
		if(temp!=-1) candi.push_back(temp + 1);
	}
	cache[idx] = *min_element(candi.begin(), candi.end());
	return cache[idx];
}


int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		ladders[x] = y;

	}

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		snakes[u] = v;
	}
	//move(1, 0);
	//cout << *min_element(answers.begin(), answers.end());
	cout << move2(1);
}