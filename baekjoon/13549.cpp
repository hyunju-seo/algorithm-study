#include<iostream>
#include<queue>

using namespace std;
bool visited[100001];
int dist[100001];

bool rangeCheck(int n) {
	if (n < 0 || n >= 100001) return false;
	return true;
}
struct Node {
	int dist;
	int nodeNum;
	bool operator < (const Node& other) const {
		return dist > other.dist;
	}
};
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < 100001; i++) {
		dist[i] = 1000000000;
	}
	priority_queue<Node> que;
	dist[n] = 0;
	que.push({ dist[n],n});
	while (!que.empty()) {
		int d = que.top().dist;
		int no = que.top().nodeNum;
		//cout << "d " << d << "    no " << no << endl;
		que.pop();
		if (visited[no]) continue;
		visited[no] = true;
		int next = no + 1;
		if (rangeCheck(next)) {
			if (!visited[next]&&dist[next]>d+1) {
				dist[next] = d + 1;
				que.push({ dist[next],next });
				
			}
		}
		next = no - 1;
		if (rangeCheck(next)) {
			//cout << "rangeCheck" << endl;

			if (!visited[next] && dist[next] > d + 1) {
				dist[next] = d + 1;
				que.push({ dist[next],next });

			}
		}

		next = no *2;
		if (rangeCheck(next)) {
			//cout << "rangeCheck" << endl;

			if (!visited[next] && dist[next] > d) {
				dist[next] = d ;
				que.push({ dist[next],next });

			}
		}
	}

	cout << dist[k] << "\n";
}