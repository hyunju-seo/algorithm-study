// https://www.acmicpc.net/problem/1260
//틀린이유: 배열의 크기를 잘못 설정해서 런타임 에러가 남
//하지만 재귀함수 자체가 스택을 구현한 것이므로 dfs에서 스택을 쓰지 말고 간단히푸는 방법

#include<iostream>

#include<vector>
#include<queue>
#include<stack>

using namespace std;
bool a[1001][1001];
//vector<int> alist[1001];

void dfs(vector<int> checked_dfs, stack<int>& stk, int m) {
	if (stk.empty()) return;
	int start = stk.top();
	bool child = false;
	for (int i = 1; i <=1000; i++) {
		if (a[start][i] && checked_dfs[i] == 0) {
			stk.push(i);
			checked_dfs[i] = 1;
			cout << i << " ";
			child = true;
			break;
		}
	}
	if (child == false) {
		stk.pop();
	}
	dfs(checked_dfs,stk,m);

}


void bfs(vector<int>& checked, queue<int>& que, int m) {   // 여러 정점 중 작은 정점을 먼저 방문 => 인접리스트 보다 인접 행렬 이용
	if (que.empty()) return;
	int start = que.front();
	cout << start<<" ";
	que.pop();

	for (int i = 1; i <= 1000; i++) {
		
		if (a[start][i] && checked[i] != 1) {
			que.push(i);
			checked[i] = 1;
		}
	}

	bfs(checked, que,m);

	
}

//간선의 수보다 정점의 수가 더 클수도 있다
int main() {
	int n, m, v;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		a[from][to] = true;
		a[to][from] = true;
	/*	alist[from].push_back(to);
		alist[to].push_back(from);*/
	}

	//dfs
	stack<int> stk;
	vector<int>checked_dfs(1001);
	stk.push(v);
	checked_dfs[v] = 1;
	cout << v << " ";

	dfs(checked_dfs, stk, m);

	cout << "\n";


	//bfs

	vector<int> checked(1001);
	queue<int> que;
	que.push(v);
	checked[v] = 1;
	bfs(checked, que, m);

	
}