#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
char s[15];
int k;
vector<int> numbers;
int minimum = 1000000000;
int maximum = -1;
bool check(int n1, int n2) {
	if (s[n1] == '<') {
		return n1 < n2;

	}
	else return n1 > n2;
}

//���� ���� num�� fill ���� �ڸ��� �� �� �ִ°�?
void dos(int num, int fill) {
	//�ε�ȣ�� �����ϴ� ���ڸ� �ϼ��� ���
	if (fill == k+1) {
		//������ ���� temp �����
		int temp = 0;
		int i = 1;
		while (!numbers.empty()) {
			int x = numbers.back();
			numbers.pop_back();
			temp += x * i;
			i *= 10;

		}
		minimum = min(temp, minimum);
		maximum = max(temp, maximum);
		return;
	}
	//���ڸ� �ϼ����ϴ� ���
	if (num > 9) return;

else if (fill==0||check(numbers[fill-1], num)) {
		numbers.push_back(num);
		dos(num + 1, fill + 1);
		numbers.pop_back();
	}
	dos(num + 1, fill);

}

int main() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> s[i];
	}
	dos(0, 0);
	cout << maximum << "\n";
	cout << minimum << "\n";
}