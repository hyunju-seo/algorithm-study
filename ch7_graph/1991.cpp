#include<iostream>

using namespace std;
int n;

struct Node {
	int left;
	int right;
};
Node tree[50];
void preorder(int node) {
	if (node == -1) return;
	cout << char(node + 'A');

	preorder(tree[node].left);
	preorder(tree[node].right);
}
void inorder(int node) {
	if (node == -1) return;

	inorder(tree[node].left);
	cout << char(node + 'A');

	inorder(tree[node].right);
}

void postorder(int node) {
	if (node == -1) return;

	postorder(tree[node].left);

	postorder(tree[node].right);
	cout << char(node + 'A');

}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char node, leftchild, rightchild;
		cin >> node >> leftchild >> rightchild;
		node = node - 'A';
		if (leftchild == '.') {
			tree[node].left = -1;
		}
		else {
			tree[node].left = leftchild-'A';
		}
		if (rightchild == '.') {
			tree[node].right = -1;
		}
		else {
			tree[node].right = rightchild - 'A';
		}
	}
	preorder(0);
	cout << endl;
	inorder(0);
	cout << endl;
	postorder(0);
	cout << endl;
}