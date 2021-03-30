//https://algospot.com/judge/problem/read/TRAVERSAL
#include<iostream>
#include<cstring>

using namespace std;

int preorder[101];
int inorder[101];
void func(int pre_start, int pre_end, int in_start, int in_end) {
	//cout << pre_start << " " << pre_end << " " << in_start << " " << in_end << endl;
	if (pre_start > pre_end) return;
	if (in_start > in_end) return;
	int root = preorder[pre_start];
	int in_root_idx = 0;
	for (int i = in_start; i <= in_end; i++) {
		if (inorder[i] == root) in_root_idx = i;
	}
	//¿Þ
	func(pre_start + 1,in_root_idx-in_start+pre_start , in_start, in_root_idx - 1);
	//¿À
	func(in_root_idx - in_start + pre_start+1, pre_end,in_root_idx+1,in_end);

	//·ç
	cout << root << " ";
}
int main() {
	int c;
	cin >> c;
	while (c != 0) {
		c -= 1;
		int n;
		cin >> n;
		memset(inorder, 0, sizeof(inorder));
		memset(preorder, 0, sizeof(preorder));
		for (int i = 0; i < n; i++) cin >> preorder[i];
		for (int i = 0; i < n; i++) cin >> inorder[i];
		func(0, n - 1, 0, n - 1);
		cout << "\n";
	}
}