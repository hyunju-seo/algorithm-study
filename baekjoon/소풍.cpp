#include<iostream>
using namespace std;

//답이 중복되지 않게 하기 위해서 가장 빠른 index의 학생을 짝지어 준다.

int pairing(bool taken[10], const bool areFriends[10][10] ,int n) {
	int firstFree = -1;
	for (int i = 0; i < n; i++) {
		if (taken[i] == false) {
			firstFree = i;
			cout << firstFree << endl;
			break;
		}
	}
	//모든 학생이 짝지어진 경우
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

		bool areFriends[10][10] = {};  // pair로 받기 보다는 친구인지 아닌지 여부를 확인해야 하므로 행렬로 나타내는 것이 좋다
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