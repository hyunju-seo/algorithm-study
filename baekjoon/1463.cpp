#include<iostream>
#include<algorithm>
using namespace std;
int vec[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int answer = 0;
	vec[1] = 0; //항상 처음 조건 잘 보기!
	vec[2] = 1;
	vec[3] = 1;
	for (int i = 4; i <= N; i++) {
		int ans_a = N-1;
		int ans_b = N-1;
		int ans_c = N-1;
		if (i % 2 == 0) {
			ans_a = 1;
			ans_a += vec[i / 2];
		}
		if (i % 3 == 0) {
			ans_b = 1;
			ans_b += vec[i / 3];
		}
		ans_c = 1;
		ans_c += vec[i - 1];
		int mini;
		mini = min(ans_a, ans_b);
		vec[i] = min(mini, ans_c);

	}
	cout << vec[N];
}