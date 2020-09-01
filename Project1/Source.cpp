//https://level.goorm.io/exam/47881/%EA%B7%BC%EB%AC%B5%EC%9E%90%ED%9D%91/quiz/1

#include <iostream>
using namespace std;
int N, K, ans;
int arr[100001];
int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	int index = 0;
	while (true) {
		if (index >= N) break;
		if (index == 0) index += K;
		else index += K - 1;
		ans++;
	}
	cout << ans << endl;
	return 0;
}