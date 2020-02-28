#include<queue>
#include<iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int K;
	cin >> K;
	queue<int> que;
	int front;
	cout << '<';
	for (int i = 1; i < N+1; i++) {
		que.push(i);
	}
	for (int j = 0; j < N-1;j++) {
		for (int i = 1; i < K; i++) {
			front = que.front();
			que.push(front);
			que.pop();
		}
		front = que.front();
		que.pop();
		//출력 방법 1.
		//cout << front << ((j == (N - 1)) ? ">" : ", ");   //cout 사용할 때, 삼항연산자 꼭 괄호 해주기!  (안해주면 에러남)
	
		cout << que.front << ", ";
		
	}
	cout << que.front() << '>';

}