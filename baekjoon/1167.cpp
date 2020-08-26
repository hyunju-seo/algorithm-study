//https://www.acmicpc.net/problem/1167
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
int v;
struct info {
	int node;
	int distance;
};
bool compare(int a, int b) {
	return a > b;
}
vector<info> tree[100005];
int numLink[100005];
int ans = 0;
int root = 0;
bool visited[100005];
int calDistance(int node) {
	vector<int> save;
	visited[node] = true;
	//cout << "node: " << node << endl;
	for (auto child : tree[node]) {
		if (visited[child.node] == false && child.node>0) {
			//cout << "visited-node-child: " << node << " - " << child.node << endl;
			int result = calDistance(child.node) + child.distance;
			save.push_back(result);
		}


	}
	//cout << node << endl;
	//for (auto a : save) {
	//	cout << a << " ";

	//}cout << endl;
	if (save.empty()) return 0;

	sort(save.begin(), save.end(), compare);

	if (save.size() > 1) {
		ans = max(ans, save[0] + save[1]);
	}
	ans = max(ans, save[0]);
	return save[0];
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> v;
	for (int i = 0; i < v; i++) {
		int node;
		cin >> node;
		while (true) {
			int connected_node ;
			cin >> connected_node;
			if (connected_node == -1) break;
			int node_distance;
			cin >> node_distance;
			info info = { connected_node,node_distance };
			
			tree[node].push_back(info);

		}
		
	}

	//cout << "root" << root << endl;
	calDistance(1);
	cout << ans<<"\n";
	
	
}