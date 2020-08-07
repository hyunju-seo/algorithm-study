#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int t[20];
int p[20];
int n;
vector<int> answers;
void chooseDate(int day, int profit) {
	
	if (day == n + 1) {
		//cout << profit << endl;
		answers.push_back(profit);
		return;

	}

	if (day + t[day] <= n + 1) {
		chooseDate(day + t[day], profit + p[day]);

	}
	chooseDate(day + 1, profit);

}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}
	
	chooseDate(1, 0);

	cout << *max_element(answers.begin(), answers.end());
}