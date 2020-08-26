#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int p[10000];
int cache[10000];
int calcache(int num) {
	if (cache[num] != -1) { return cache[num]; }
	for (int i = 1; i <= num;i++) {
		cache[num]=min(cache[num],p[i])

	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
}
