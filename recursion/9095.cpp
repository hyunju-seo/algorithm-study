#include<iostream>
#include<cstring>
int cache[20];   //n을 1,2,3의 합으로 나타내는 방법의 수

using namespace std;

int met(int n) {
	if (n <= 2) {
		cache[n] = n;
		return n;
	} 
	if (n == 3) {
		cache[n] = 4;
		return 4;
	}


	int& ret = cache[n];
	if (ret != -1) {
		return ret;
	}
	ret = met(n - 1) + met(n - 2) + met(n - 3);
	return ret;


}


int main() {
	int t;
	cin >> t;
	while (t != 0) {
		t--;
		memset(cache, -1, sizeof(cache));
		int n;
		cin >> n;
		cout<<met(n)<<"\n";
	}
}