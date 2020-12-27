#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<long long> cards(n);
	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}
	sort(cards.begin(), cards.end());
	int cnt = 1;
	int maxcnt = 1;
	long long max = cards[0];
	for (int i = 1; i < n; i++) {
		if (cards[i] == cards[i - 1]) {
			cnt += 1;
		}
		else {
			cnt = 1;

		}
		if (cnt > maxcnt) { max = cards[i]; 
		maxcnt = cnt;
		}
		
	}
	cout << max << "\n";
}