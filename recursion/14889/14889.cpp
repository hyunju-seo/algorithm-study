#include<iostream>
#include<vector>
using namespace std;
int s[30][30];
int n;
int ans=10000000;
//startTeam: 1, linkTeam: 2
int team[30];
int ability_d() {
	int start = 0;
	int link = 0;
	for (int i = 1; i <= n;i++) {
		for (int j = i+1; j <= n; j++) {
			if (team[i] == 1 && team[j] == 1) {
				start += s[i][j] + s[j][i];
			}
			else if (team[i] == 2 && team[j] == 2) {
				link += s[i][j] + s[j][i];

			}
		}

	}
	if ((start - link) < 0) return (link - start);
	return start - link;
}

//idx가 어떤 팀에 속할지를 정하는 함수
void select(int idx, int s, int l) {
	if (s == n / 2 && l == n / 2) {
		if (ans > ability_d()) ans = ability_d();
		return;
	}
	if (idx >= n + 1) return;

	//startTeam을 고르는 경우
	if (s < n / 2) {
		team[idx] = 1;
		select(idx + 1, s + 1, l);
		
	}
	//linkTeam을 고르는 경우
	if (l < n / 2) {
		team[idx] = 2;
		select(idx + 1, s, l + 1);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> s[i][j];
		}
	}
	select(1, 0, 0);
	cout << ans << "\n";

}