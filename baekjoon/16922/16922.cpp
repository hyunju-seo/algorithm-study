#include<iostream>
#include<set>

using namespace std;
int n;
set<int> answers;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	//func(0, 0);
	int sum = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= n; k++) {
				for (int l = 0; l <= n; l++) {
					if (i + j + k + l != n) continue;
					sum = 0;
					sum = 1 * i + 5 * j + 10 * k + l * 50;
					answers.insert(sum);
				}
			}
		}
	}
	cout << answers.size() << "\n";
}