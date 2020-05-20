#include<cstring> 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int lotto[55];
int k;



int main() {
	
	while (true) {
		cin >> k;
		if (k == 0) break;
		memset(lotto, -1, sizeof(lotto));
		vector<int> order(k);
		for (int i = 0; i < 6; i++) {
			order[i] = 1;
		}
		for (int i = 6; i < k; i++) order[i] = 0;
		for (int i = 0; i < k; i++) {
			cin >> lotto[i];
		} 
		do {
			for (int i = 0; i < k; i++) {
				if (order[i] == 1) cout << lotto[i] << " ";
			}
			cout << "\n";
		} while (prev_permutation(order.begin(), order.end()));
		cout << "\n";
	}

	

}