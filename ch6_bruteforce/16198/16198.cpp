#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n;
int w[20];
bool deleted[20];
vector<int> answers;
void getMaxEnergy(int idx, int sum, int remain) {

	int minidx=idx;
	for (int i = idx+1; i < n; i++) {
		if (!deleted[i]) {
			minidx = i;
			break;
		}
	}
	int maxidx = idx;
	for (int i = idx-1; i >-1; i--) {
		if (!deleted[i]) {
			maxidx = i;
			break;
		}
	}
	sum += w[minidx] * w[maxidx];
	if (remain == 1) {
		answers.push_back(sum);
		return;
	}
	deleted[idx] = true;

	for (int i = 1; i < n - 1; i++) {
		if (!deleted[i]) {
			getMaxEnergy(i, sum, remain - 1);
	
		}
	}

	deleted[idx] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}

	int remain = n - 2;
	for (int i = 1; i < n - 1; i++) {
		getMaxEnergy(i, 0, remain);

	}

	sort(answers.begin(), answers.end());
	cout << answers.back() << endl;
}