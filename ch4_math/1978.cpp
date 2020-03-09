#include<iostream>
using namespace std;
bool isPrime(int n) {
	if (n <2) return false;

	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) { return false; }
	}
	return true;
}

int main() {
	int N;
	cin >> N;
	int answer = 0;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (isPrime(n) == true) {
			answer++;
		}
	}
	cout<< answer;
}