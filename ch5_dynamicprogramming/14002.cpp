#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> D(N);
	vector<vector<int>> sequence(N); //수열을 저장하는 배열
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A[i] = a;
	}



	for (int i = 0; i < N; i++) {
		D[i] = 1;
		sequence[i].push_back(A[i]);
		for (int j = 0; j < i; j++) {
			if (A[j]<A[i] && D[j] + 1>D[i]) {
				sequence[i].clear();
				D[i] = D[j] + 1;
				sequence[i]=sequence[j];
				sequence[i].push_back(A[i]);

			}
		}

	}
	

	int index = 0;
	for (int i = 1; i < N; i++) {
		if (D[i] > D[index]) {
			index = i;
		}
	}
	cout << D[index] << endl;
	for (auto a : sequence[index]) {
		cout << a<<" ";
	}
}