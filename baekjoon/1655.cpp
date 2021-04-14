//https://www.acmicpc.net/problem/1655
#include<iostream>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	priority_queue<int> leftQueue;
	priority_queue<int,vector<int> , greater<int>> rightQueue;
	int rsize = 0;
	int lsize = 0;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		if (leftQueue.empty()) {
			leftQueue.push(t);
			lsize += 1;
		}
		else if (leftQueue.top() < t) {
			rightQueue.push(t);
			rsize += 1;
			if (rsize > lsize) {
				leftQueue.push(rightQueue.top());
				rightQueue.pop();
				lsize += 1;
				rsize -= 1;
			}

		}
		else {
			leftQueue.push(t);
			lsize += 1;
			if (lsize > rsize + 1) {
				rightQueue.push(leftQueue.top());
				leftQueue.pop();
				rsize += 1;
				lsize -= 1;
			}
		}

		cout << leftQueue.top() << "\n";
	}
}
