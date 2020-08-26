#include<iostream>
using namespace std;
bool nums[1000001];  //false로 초기화
//false면 소수임 
//true면 소수 아님
int main() {
	int M;
	int N;
	cin >> M;
	cin >> N;
	nums[1] = true;
	for (int i = 2; i * i <= N; i++) {   
		if (nums[i] == false) {
			for (int j = i +i; j < N + 1; j += i) {
				nums[j] = true;

			}
		}

	}
	for (int i = M; i < N+1; i++) {

		if (nums[i] == false) {
			cout << i<<"\n";
		}
	}

}