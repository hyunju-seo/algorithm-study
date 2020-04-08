#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> d(n);   //i���� ������ ���� ū ���� ��
	vector<int> d2(n);   //i���� �����ϴ� ���� ū ������                                                    		cin >> a[i];

	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	d[0] = a[0];
	for (int i = 1; i < n; i++) {
		d[i] = max(d[i - 1] + a[i], a[i]);
	}
	d2[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		d2[i]= max(d2[i + 1] + a[i], a[i]);
	}

	int ans = d[0];   //ù �õ����� ans=0���� �����ؼ� Ʋ��
	                  //ans=0���� �ϸ� ��� ���� - �� ��� ���� �߻�
	for (int i = 1; i < n; i++) {
		ans = max(d[i], ans);
	}
	for (int i = 1; i < n-1; i++) {
		ans = max(ans, d[i - 1] + d2[i + 1]);
	}
	cout << ans<<"\n";
}