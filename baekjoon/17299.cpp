#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int freq[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> vec(n);
	stack<int> stk;
	vector<int>answer(n,-1);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		freq[vec[i]] += 1;
	}
	
	stk.push(0);
	for (int i = 1; i < n; i++) {
		while (!stk.empty()&&freq[vec[i]] > freq[vec[stk.top()]]) { //반드시 stk.empty가 뒤에 조건 보다 먼저 나와야 된다
			answer[stk.top()] = vec[i];
			stk.pop();
		}
		stk.push(i);
	
	}

	for (auto a : answer) {
		cout << a<<' ';
	
	}
}