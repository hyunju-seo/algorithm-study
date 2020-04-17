// https://www.acmicpc.net/problem/1748
#include<iostream>
#include<cmath>   //pow 쓰려면 추가 하기
using namespace std;
int digits[10];   //자릿수가 i인 수의 개수
int main() {
	int index = 1;
	for (int i = 1; i < 100000000; i*=10) {
		
		digits[index++] = 9 * i;
	}
	digits[9] = 1;

	int n;
	cin >> n;

	int y = n;
	int x = 0;
	while (y != 0) {
		x++;
		y /= 10;
	
	}
	int ans = (n - pow(10, x - 1) + 1) * x;          //자릿수가 n과 같은 수의 개수

	//자릿수가 n보다 작은 수의 개수
	while (x != 0) {
		x -= 1;
		ans =ans+(digits[x]*x);
	}
	cout << ans<<"\n";
}