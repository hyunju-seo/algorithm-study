#include<iostream>
#include<vector>
using namespace std;
//소수는 2보다 커야 한다@
int main() {
	int M;
	int N;
	cin >> M;
	cin >> N;

	vector<bool> nums(N+1);
	for (int i = 1; i < N+1; i++) {
		nums[i] = true; //소수임
	}
	nums[1] = false;
	for (int i = 2; i < N + 1; i++) {  //i*i<N+1 까지 하면 됨
		if (nums[i] == true) {
			int n = 2;
			while (i*n<=N) {
				nums[i * n] = false;
				n++;
			}
		}
	}
	
	for (int i = M; i < N + 1; i++) {
		if (nums[i] == true) {
			cout << i<<"\n";
		}
	}

}