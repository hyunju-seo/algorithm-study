//https://algospot.com/judge/problem/read/RUNNINGMEDIAN

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
	int c;
	cin >> c;
	while (c != 0) {
		c -= 1;
		int n, a, b;
		cin >> n >> a >> b;
		vector<int> A(n);
		priority_queue<int, vector<int>, greater<int>> minheap;
		priority_queue<int, vector<int>, less<int>> maxheap;

		A[0] = 1983;
		for (int i = 1; i < n; i++) 
			A[i] = (A[i - 1] *(long long) a  + b) % 20090711;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (minheap.size() == maxheap.size()) 
				maxheap.push(A[i]);
			
			else 
				minheap.push(A[i]);
			if (!minheap.empty()&&!maxheap.empty()) {
		
				int maxtop = maxheap.top();
				int mintop = minheap.top();
				if (maxtop > mintop) {
					maxheap.pop();
					minheap.pop();
					maxheap.push(mintop);
					minheap.push(maxtop);
				}
			}
			//cout << maxheap.top()<<endl;
			ans=(ans+maxheap.top()) % 20090711;
		}
		
		cout << ans << "\n";
	}
}