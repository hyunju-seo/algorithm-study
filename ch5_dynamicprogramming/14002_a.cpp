/*보통 최대 최소를 구하라고 하지만, 요소를 구하라고 하는 경우에는
대부분 역추적 사용=> 왜 값이 이렇게 변하게 됐는지를 추적*/
#include<iostream>
#include<vector>
using namespace std;
void go(int index,const vector<int> &v,const vector<int> &a) {
	if (index == -1) {
		return ;
	}
	 
	go(v[index], v, a);
	cout << a[index] << " ";


}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> d(n);  // 가장 긴 증가하는 부분 수열의 길이
	vector<int> v(n,-1);  // 앞에 숫자

	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
				v[i] = j;
			}
		}
	}

	int index = 0;
	for (int i = 1; i < n; i++) {
		if (d[i] > d[index]) {
			index = i;
		}
	}
	cout << d[index] << endl;
	go(index,v,a);

}