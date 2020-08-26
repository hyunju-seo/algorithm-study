#include<iostream>
#include<vector>

using namespace std;
int n;
vector<int> vec(30);
int arr[30][30];
int sum[30][30];

bool check(int num, int idx) {
	for (int j = 0; j < idx; j++) {
		int s = sum[j][idx - 1] + num;
		if (arr[j][idx] == 0) {
			if (s != 0) return false;
		}
		else if (arr[j][idx] < 0) {
			if (s >= 0) return false;
		}
		else {
			if (s <= 0) return false;
		}
		sum[j][idx] = sum[j][idx - 1] + num;

	}
	sum[idx][idx] = num;
	vec[idx] = num;
	return true;
}

bool choice(int idx) {
	if (idx >= n)  return true;
	if (arr[idx][idx] == 0) {
		
		return check(0, idx) && choice(idx + 1);
	}


	for (int i = 1; i <= 10; i++) {
		int num = i * arr[idx][idx];
		if (check(num, idx) && choice(idx + 1)) return true;

	}
	return false;

}

int main() {
	cin >> n;
	string inp;
	cin >> inp;
	int x = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (inp[x] == '0') {
				arr[i][j] = 0;
			}
			else if (inp[x] == '+') {
				arr[i][j] = 1;
			}
			else if (inp[x] == '-') {
				arr[i][j] = -1;
			}
			x++;
		}
	}
	choice(0);
	for (int i = 0; i < n; i++) {
		cout << vec[i] << " ";
	}
}