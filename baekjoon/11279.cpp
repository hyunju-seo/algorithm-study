#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> heap;
void push(int num) {
	heap.push_back(num);
	int now = heap.size() - 1;
	while (true) {
		if (now <= 0) break;
		if (heap[now] > heap[(now - 1) / 2]) {
			swap(heap[now], heap[(now - 1) / 2]);
			now = (now - 1) / 2;
		}
		else break;
	}

}


int pop() {
	int ret = heap[0];
	heap[0] = heap.back();
	heap.pop_back();
	int now = 0;
	while (true) {
		int left = now * 2 + 1;
		int right = now * 2 + 2;
		if (left >= heap.size()) break;
		if (right >= heap.size()) {
			if (heap[now] >= heap[left]) break;
			swap(heap[now], heap[left]);
			now = left;
		}
		else {
			int maxIdx;
			if (heap[left] > heap[right]) maxIdx = left;
			else maxIdx = right;
			if (heap[now] >= heap[maxIdx]) break;
			swap(heap[now], heap[maxIdx]);
			now = maxIdx;
		}

	}

	return ret;
}


int main() {
	int n;
	vector<int>answers;
	cin >> n;
	while (n != 0) {
		n -= 1;
		int t;
		cin >> t;
		if (t == 0) {
			if (heap.size() == 0) { 
				answers.push_back(0); 
			//cout << "------------" << endl;
			//for (auto h : heap) {
			//	cout << h << endl;
			//}
			}
			else {
				answers.push_back(pop());
				//cout << "------------" << endl;
				//for (auto h : heap) {
				//	cout << h << endl;
				//}
			}
		}
		else {
			push(t);
		}
	}
	for (auto a : answers) {
		cout << a << "\n";
	}
}