#include<iostream>
using namespace std;
long long d[91][2];
int main() {
	int N;
	cin >> N;
	d[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		d[i][0] += (d[i - 1][0] + d[i - 1][1]);
		d[i][1] += d[i - 1][0];

	}
	cout << d[N][1] + d[N][0];
}


//이 문제는 0,1 만 있음 => 1차원 배열 이용 가능
//d[n] => 길이가 n 인 이친수 개수 
//d[n]=d[n-1]                        + d[n-2]
//     d[n]의 마지막이 0인 경우        마지막이 1인 경우 (앞이 무조건 0이므로 d[n-2]의 수와 같다)
//#include <iostream>
//using namespace std;
//long long d[91];
//int main() {
//	int n;
//	cin >> n;
//	d[1] = 1;
//	d[2] = 1;
//	for (int i = 3; i <= n; i++) {
//		d[i] = d[i - 1] + d[i - 2];
//	}
//	cout << d[n] << '\n';
//	return 0;
//}