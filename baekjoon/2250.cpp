#include<iostream>
#include<algorithm>
using namespace std;
struct Node {
	int left;
	int right;
	int level;
	int col;
};
int n;
Node tree[10005];
int order;

int parentnum[10005];
void inorder(int node, int depth) {
	if (node == -1) return;
	inorder(tree[node].left, depth+1);
	//node 출력
	tree[node].level = depth;
	tree[node].col = ++order;
	inorder(tree[node].right, depth+1);
}
int leftmincol[10005]; // 해당 level에서 최소인 column
int rightmaxcol[10005];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int node, leftchild, rightchild;
		cin >> node >> leftchild >> rightchild;
		tree[node].left = leftchild;
		tree[node].right = rightchild;
		if (leftchild != -1) parentnum[leftchild] += 1;
		if (rightchild != -1)parentnum[rightchild] += 1;
	}
	int root = 0;
	for (int i = 1; i <= n; i++) {
		if (parentnum[i] == 0) root = i;
	}
	inorder(root, 1);
	int maxdepth = 0;
	for (int i = 1; i <= n; i++) {
		int level = tree[i].level;
		int col = tree[i].col;
		if (leftmincol[level] == 0) {
			leftmincol[level] = col;
		}
		else {
			leftmincol[level] = min(col,leftmincol[level]);

		}
		rightmaxcol[level] = max(rightmaxcol[level], col);
		maxdepth = max(maxdepth, col);
	}
	int ans = 0;
	int ans_level = 0;
	for (int i = 1; i <= maxdepth;i++) {
		if (ans < rightmaxcol[i] - leftmincol[i] + 1) {
			ans = rightmaxcol[i] - leftmincol[i] + 1;
			ans_level = i;
		}
	}
	cout << ans_level << ' ' << ans << endl;



}