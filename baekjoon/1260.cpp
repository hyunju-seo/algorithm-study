// https://www.acmicpc.net/problem/1260
//Ʋ������: �迭�� ũ�⸦ �߸� �����ؼ� ��Ÿ�� ������ ��
//������ ����Լ� ��ü�� ������ ������ ���̹Ƿ� dfs���� ������ ���� ���� ������Ǫ�� ���

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


void bfs(vector<int>& checked, queue<int>& que, int m) {   // ���� ���� �� ���� ������ ���� �湮 => ��������Ʈ ���� ���� ��� �̿�
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

//������ ������ ������ ���� �� Ŭ���� �ִ�
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