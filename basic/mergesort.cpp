#include<iostream>

using namespace std;
int a[] = { 4,7,1,8,5,6,3,10,2,9 };
int temp[10];
void merge(int fstart, int fend, int lstart, int lend) {
	int first = fstart;
	int last = lstart;
	int idx = fstart;
	while (first <= fend && last <= lend) {
		if (a[first] > a[last]) {
			temp[idx++] = a[last++];
		}
		else {
			temp[idx++] = a[first++];
		}
	}
	while (first <= fend) {
		temp[idx++] = a[first++];

	}
	while (last <= lend) {
		temp[idx++] = a[last++];
	}
	for (int i = fstart; i <= lend; i++) {
		a[i] = temp[i];
	}
}

void msort(int start, int end) {
	if (start == end) { return; }
	int mid = (start + end) / 2;
	msort(start, mid);
	msort(mid + 1, end);
	merge(start, mid,mid+1,end);
}


int main() {
	msort(0, 9);
	for (auto t : a) {
		cout << t << " ";
	}
}