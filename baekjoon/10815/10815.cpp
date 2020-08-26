#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long cards[500000];
int n;

bool search( long long num ) {
	int left = 0;
	int right = n-1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (cards[mid] == num) return true;
		else if (cards[mid] > num) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}
	sort(cards, cards+n);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) 
	{
		int num;
		cin >> num;
		cout << search(num) << " ";
	}

}
