#include<iostream>
#include<algorithm>
using namespace std;
// long long 안 하면 런타임 에러 
long long num_5(int n) {
	long long answer = 0;

	for (long long i = 5; i <= n; i *= 5) {
		answer += n / i;
	}
	return answer;
}

long long num_2(int n) {
	long long answer = 0;

	for (long long i = 2; i <= n; i *= 2) {
		answer += n / i;
	}
	return answer;
}
int main() {
	int n;
	int m;
	cin >> n;
	cin >> m;
	long long five = num_5(n) - num_5(m) - num_5(n - m);
	long long two = num_2(n) - num_2(m) - num_2(n - m);
	cout << min(five, two);
	

}