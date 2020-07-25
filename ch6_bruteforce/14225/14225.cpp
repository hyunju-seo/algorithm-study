#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int input[30];
int n;
bool answers[2000000];
void getAnswer(int sum, int idx) {
	if (idx == n) {
		answers[sum]=true;
		return; 
	}
	getAnswer(sum + input[idx], idx + 1);
	getAnswer(sum, idx + 1);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i];

	}
	getAnswer(0, 0);
	for (int i = 1; i < 2000000;i++) {
		if (answers[i] == false) {
			cout << i << "\n";
			break;
		}
	}
}