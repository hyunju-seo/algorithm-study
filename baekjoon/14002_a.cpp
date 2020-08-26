/*���� �ִ� �ּҸ� ���϶�� ������, ��Ҹ� ���϶�� �ϴ� ��쿡��
��κ� ������ ���=> �� ���� �̷��� ���ϰ� �ƴ����� ����*/
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
	vector<int> d(n);  // ���� �� �����ϴ� �κ� ������ ����
	vector<int> v(n,-1);  // �տ� ����

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