//https://algospot.com/judge/problem/read/FORTRESS
//2. 691p
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct Info {
	int x;
	int y;
	int r;
};
int n;

vector<int> nodes[101];
vector<Info> walls;

int mul(int  x) {
	return x * x;
}


bool enclose(int root, int i) {
	if (walls[root].r <= walls[i].r) return false;
	if (mul(walls[root].x - walls[i].x) + mul(walls[root].y - walls[i].y) < mul( walls[root].r - walls[i].r)) return true;
	return false;
}
bool subtree(int root, int a) {
	if (!enclose(root, a)) return false;
	for (int i = 0; i < n; i++) {
		if (root != i && i != a && enclose(root, i) && enclose(i, a)) return false;
	}
	return true;

}
int longest = 0;
int func(int root) {
	vector<int> ans;
	for (auto child:nodes[root]) {
		ans.push_back(func(child)+1);
	}
	if (ans.empty()) return 0;
	sort(ans.begin(), ans.end());
	if(ans.size()>=2) longest = max(longest, ans[ans.size() - 1] + ans[ans.size() - 2]);
	return ans.back();

}
void makeTree(int root) {
	for (int i = 0; i < n; i++) {
		if (subtree(root, i)) {
			nodes[root].push_back(i);
			makeTree(i);
		}
	}
}



int main() {
	int c;
	cin >> c;
	while (c != 0) {
		c -= 1;
		cin >> n;
		walls.clear();
		longest = 0;
		for (int i = 0; i < 101; i++) {
			nodes[i].clear();
		}
		for (int i = 0; i < n; i++) {
			int x, y, r;
			cin >> x >> y >> r;
			Info temp;
			temp.x = x;
			temp.y = y;
			temp.r = r;
			walls.push_back(temp);

		}
		makeTree(0);

		int ret= func(0);
		
		ret = max(ret, longest);
		cout << ret << "\n";
	}
}