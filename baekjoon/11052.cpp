#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int p[10005];
int cache[10005]; //n개의 카드를 사는데 지불하는 최대 금액
//cache[n]을 구하는 함수  
int calCache(int num) {
	
	if (num==0) {
		cache[num] = num;	

		return cache[num];
	}
	if (cache[num] != -1) return cache[num];
	int& ret = cache[num];
	for (int i = 1; i <= num; i++) {

		ret = max(ret, p[i] + calCache(num - i));
	}

	return ret;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	memset(cache, -1, sizeof(cache));
	cout<<calCache(n)<<endl;
}