#include<iostream>
#include<list>
#include<vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	int K;
	cin >> K;
	list<int> ppl;
	for (int i = 1; i < N + 1; i++) {
		ppl.push_back(i);
	}
	list<int>::iterator it = ppl.begin();
	vector<int> answer;
	while (!ppl.empty()) {
		for (int i = 1; i < K; i++) {
			it++;
			if (it == ppl.end()) {
				it = ppl.begin();
			}

		}


		answer.push_back(*it);


		it = ppl.erase(it);
		if (it == ppl.end()) {
			it = ppl.begin();
		}

	}

	cout << '<';
	for (int i = 0; i < answer.size() - 1; i++) {
		cout << answer[i] << ", ";
	}
	cout << answer.back();
	cout << '>';
	
}