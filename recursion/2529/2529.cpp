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

//현재 숫자 num이 fill 이후 자리에 들어갈 수 있는가?
void dos(int num, int fill) {
	//부등호를 만족하는 숫자를 완성한 경우
	if (fill == k+1) {
		//저장한 수로 temp 만들어
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
	//숫자를 완성못하는 경우
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