#include<iostream>
using namespace std;

//���� �ߺ����� �ʰ� �ϱ� ���ؼ� ���� ���� index�� �л��� ¦���� �ش�.

int pairing(bool taken[10], const bool areFriends[10][10] ,int n) {
	int firstFree = -1;
	for (int i = 0; i < n; i++) {
		if (taken[i] == false) {
			firstFree = i;
			cout << firstFree << endl;
			break;
		}
	}
	//��� �л��� ¦������ ���
	if (firstFree == -1) { cout << "return1" << endl; return 1;
	}
	int ret = 0;
	for (int i = firstFree + 1; i < n; i++) {
		if (taken[i] == false && areFriends[firstFree][i] == true) {
			taken[firstFree] = true;
			taken[i] = true;

			ret += pairing(taken, areFriends, n);
			taken[firstFree] = taken[i] = false;
		}

	}cout << "ret= " << ret << endl;
	return ret;


}


int main() {
	int c;
	cin >> c;
	while (c != 0) {
		c--;
		int n, m;
		cin >> n >> m;

		bool areFriends[10][10] = {};  // pair�� �ޱ� ���ٴ� ģ������ �ƴ��� ���θ� Ȯ���ؾ� �ϹǷ� ��ķ� ��Ÿ���� ���� ����
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			areFriends[a][b] = true;
			areFriends[b][a] = true;
		}
		bool taken[10] = {};
		cout << pairing(taken, areFriends, n)<<"\n";


	}
}