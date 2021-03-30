//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//int workingHours[10001];
//vector<int> reversePrecedence[10001];
//bool visited[10001];
//int finalHours[10001];
//int dfs(int idx) {
//	if (visited[idx]) return finalHours[idx];
//	int ret = 0;
//	visited[idx] = true;
//
//	for (auto w : reversePrecedence[idx]) {
//		ret = max(ret, dfs(w));
//	}
//	finalHours[idx] = ret + workingHours[idx];
//	return  ret + workingHours[idx];
//}
//
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> workingHours[i];
//		int temp, t;
//		cin >> temp;
//		for (int j = 0; j < temp; j++) {
//			cin >> t;
//			reversePrecedence[t].push_back(i);
//		}
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		ans = max(ans, dfs(i));
//	}
//	cout << ans << "\n";
//}
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int workingHours[10001];
vector<int> precedence[10001];
int indegree[10001];
int finalHours[10001];
int precedenceHours[10001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> workingHours[i];
		int temp, t;
		cin >> temp;
		for (int j = 0; j < temp; j++) {
			cin >> t;
			//precedence[i].push_back(t);
			precedence[t].push_back(i);
			indegree[i] += 1;
		}
	}
	queue<int> que;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			que.push(i); 
			finalHours[i] = workingHours[i];
		}
	}
	while (!que.empty()) {
		int f = que.front();
		que.pop();
		for (auto p : precedence[f]) {
			indegree[p] -= 1;
			precedenceHours[p] = max(finalHours[f], precedenceHours[p]);
			if (indegree[p] == 0) {
				que.push(p);
				finalHours[p] = workingHours[p] + precedenceHours[p];
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(finalHours[i], ans);
	}
	cout << ans << "\n";
}