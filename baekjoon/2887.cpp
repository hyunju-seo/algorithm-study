#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include <cmath>       
using namespace std;

struct Pos {
	int x;
	int y;
	int z;
};
struct Kru {
	int idx1;
	int idx2;
	int distance;
	bool operator< (const Kru& other) const {
		return distance < other.distance;
	}
};
int root[100001];
int h[100001];
int find(int x) {

	if (x == root[x]) return x;
	root[x] = find(root[x]);
	//cout << "find(" << x << ")" << root[x] << endl;

	return root[x];
}

void Union(int a, int b) {

	int roota = find(a);
	int rootb = find(b);
	//cout << "before union " << roota << " " << rootb << endl;

	if (roota == rootb) return;
	if (h[roota] > h[rootb]) swap(roota, rootb);

	root[roota] = rootb;
	if (h[roota] == h[rootb]) h[rootb] += 1;
	//cout << "after union " << root[roota] << " " << root[rootb] << endl;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) root[i] = i;
	vector<pair<int, int>> X;
	vector<pair<int, int>> Y;
	vector<pair<int, int>> Z;
	unordered_map<int, Pos> pos;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		X.push_back({ x, i });
		Y.push_back({ y, i });
		Z.push_back({ z, i });
		pos.insert({ i, {x,y,z} });

	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());
	vector<Kru> kru;
	for (int i = 0; i < n - 1; i++) {
		int idx1 = X[i].second;
		int idx2 = X[i + 1].second;
		Pos p1 = pos[idx1];
		Pos p2 = pos[idx2];
		kru.push_back({ idx1, idx2, min({ abs(p1.x - p2.x), abs(p1.y - p2.y), abs(p1.z - p2.z) }) });
		idx1 = Y[i].second;
		idx2 = Y[i + 1].second;
		p1 = pos[idx1];
		p2 = pos[idx2];
		kru.push_back({ idx1, idx2, min({ abs(p1.x - p2.x), abs(p1.y - p2.y), abs(p1.z - p2.z) }) });
		idx1 = Z[i].second;
		idx2 = Z[i + 1].second;
		p1 = pos[idx1];
		p2 = pos[idx2];
		kru.push_back({ idx1, idx2, min({ abs(p1.x - p2.x), abs(p1.y - p2.y), abs(p1.z - p2.z) }) });

	}
	sort(kru.begin(), kru.end());
	int krusize = kru.size();
	int ans = 0;
	//for (Kru t : kru) {
	//	cout << t.idx1 << "  " << t.idx2 << "  " << t.distance << endl;
	//}cout << endl;
	for (int i = 0; i < krusize; i++) {
		int idx1 = kru[i].idx1;
		int idx2 = kru[i].idx2;
		//cout << idx1<<"  "<<idx2<<" "<<find(idx1)<<"  " << find(idx2) << endl;
		if (find(idx1) == find(idx2)) continue;
		//cout << idx1 << "  " << idx2 << endl;
		ans += kru[i].distance;
		//cout<< find(idx1) << " " << find(idx2) << endl;
		Union(idx1, idx2);
		//cout << "union( " << idx1 << " " << idx2 << "): " << find(idx1) << " " << find(idx2) << endl<<endl;
	}
	cout << ans << "\n";
}