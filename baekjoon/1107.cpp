#include<iostream>
#include<algorithm>

using namespace std;
bool broken[10];
int main() {

	//�������� �޾Ƽ� �ѱ��ھ� ���� ���
	//���ڷ� �޾Ƽ� 10���� ������ ���
	//channel_length ������ Ʋ��
	int channel;
	cin >> channel;
	int x = channel;

	int broken_num;
	cin >> broken_num;
	for (int i = 0; i < broken_num; i++) {
		int n;
		cin >> n;
		broken[n] = true;
		
	}

	int ans = abs(channel - 100);
	for (int i = 0; i <= 1000000;i++) {
		int c;
		c = i;
		int channel_length = 0;

		bool valid = true;

		while (c>0) {

			if (broken[c % 10] == true) {
				valid = false;
				break;


			}
			channel_length++;

			c = c / 10;

		}
		if (i == 0) {
			if (broken[0] == true) {
				valid = false;

			}
			channel_length = 1;
		}
		if (valid == true) { //���峪�� �ʾҴٸ�
			ans = min(abs(channel - i) + channel_length, ans);
		}
	}
	cout << ans<<endl;
}
//
