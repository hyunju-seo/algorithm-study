#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
bool desc(int a, int b) {
	return a > b;
}
int main() {
	int n;
	cin >> n;
	vector<string> slist;
	for (int i = 0; i < n; i++) {
		
		string str;
		cin >> str;
		slist.push_back(str);
	}
	vector<int> alphasum(40) ;
	for (auto str : slist) {
		for (int i = 0; i <str.size(); i++) {
			alphasum[str[i] - 'A'] += pow(10, str.size() - i - 1);
		}
	}
	sort(alphasum.begin(), alphasum.end(),desc);
	
	int mul = 9;
	int sum = 0;
	for (int i = 0; i < alphasum.size(); i++) {
		if (alphasum[i] == 0) {
			break;
		}
		sum += alphasum[i] * mul;
		mul--;
	}
	cout << sum << endl;
}