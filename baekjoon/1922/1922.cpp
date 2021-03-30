#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<pair<int, int>> com[1001];
bool visited[1001];
struct comlink {
	int a;
	int b;
	int c;
};
struct compare {
	bool operator() (comlink x, comlink y){
		if (x.c == y.c) {
			if (x.a == y.a) return x.a > y.a;
			return x.b > y.b;
		}
		return x.c > y.c;
	}
};


int main() {
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		com[a].push_back({ b,c });
		com[b].push_back({ a,c });

	}
	priority_queue<comlink, vector<comlink>, compare> que;
	int a=0;
	for (int i = 1; i < 1001; i++) {
		if (com[i].size() != 0) {
			a = i;
			break;
		}
	}
	for (int i = 0; i < com[a].size(); i++) {
		que.push(comlink{ a,com[a][i].first, com[a][i].second });
	}
	int cost = 0;
	int nodeNum = 1;
	visited[a] = true;
	while (nodeNum != n) {

		comlink temp= que.top();
		que.pop();
		if (!visited[temp.a]) a = temp.a;
		else if (!visited[temp.b]) a = temp.b;
		else continue;
		if (visited[a]) continue;
		cost += temp.c;
		visited[a] = true;
		nodeNum += 1;
		for (int i = 0; i <com[a].size() ; i++) {
			que.push(comlink{a,com[a][i].first, com[a][i].second});
		}

	}
	cout << cost;



}