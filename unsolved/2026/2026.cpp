#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> friends[901];
//picked
vector<int> picked;
bool check[901];
int k, n, f;
//1���� ������ ��, ����������
void dfs(int start, int toPick) {
	if (toPick == 0) return;
	//���� start�� n�� �ʰ��Ѵٸ�
	if (friends[start].empty()) {
		//check�� picked �����
		if (start + 1 > n) { cout << -1;  return; }
		dfs(start + 1, k);
	}
	check[start] = true;
	picked.push_back(start);
	for (int i = 0; i < friends[start].size();i++) {
		int next = friends[start][i];
		if (check[next] == false) {
			dfs(next, toPick - 1);
		}
	}
}

int main() {

	cin >> k >> n >> f;
	for (int i = 0; i < f; i++) {
		int f1, f2;
		cin >> f1 >> f2;
		friends[f1].push_back(f2);
		friends[f2].push_back(f1);

	}
	for (int i = 1; i <= n; i++) {
		sort(friends[i].begin(), friends[i].end());
	}

}