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


//�� ������ 0,1 �� ���� => 1���� �迭 �̿� ����
//d[n] => ���̰� n �� ��ģ�� ���� 
//d[n]=d[n-1]                        + d[n-2]
//     d[n]�� �������� 0�� ���        �������� 1�� ��� (���� ������ 0�̹Ƿ� d[n-2]�� ���� ����)
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