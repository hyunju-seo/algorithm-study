#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool isFriend[4001][4001];
int numberOfFriend[4001];
vector<int> friends[4001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int friend1, friend2;
		cin >> friend1 >> friend2;
		numberOfFriend[friend1] += 1;
		numberOfFriend[friend2] += 1;
		friends[friend1].push_back(friend2);
		friends[friend2].push_back(friend1);

		isFriend[friend1][friend2] = true;
		isFriend[friend2][friend1] = true;

	}
	int ans;
	bool yes = false;
	int a, b, c;
	for (int i = 1; i <= 4000; i++) {
		a = i;
		for (int j = 0; j < friends[i].size(); j++) {
			for (int k = j+1; k < friends[i].size(); k++) {
				b = friends[i][j];
				c = friends[i][k];
				//cout << a << " " << b << " " << c << endl;
				if (!isFriend[b][c]) continue;
				if (!yes) ans = numberOfFriend[a] + numberOfFriend[b] + numberOfFriend[c] - 6;
				yes = true;
				ans = min(ans, numberOfFriend[a] + numberOfFriend[b] + numberOfFriend[c] - 6);
				//cout << a << " " << b << " " << c << " , " << ans << endl;
			}
		}
	}
	if (!yes) cout << -1 << "\n";
	else cout << ans << "\n";

}