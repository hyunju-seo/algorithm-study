//�ð� �ʰ��� ����
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> vec_sorted;
	vector<int> vec;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
		vec_sorted.push_back(a);

	}
	sort(vec_sorted.begin(), vec_sorted.end());
	for (int i = 0; i < N-1; i++) {

		vector<int>::iterator it;
		it=find(vec_sorted.begin(), vec_sorted.end(), vec[i]);  //find���� ã�� �� �ð� �ʰ� �Ǵ� ��,,,!
		if (it != vec_sorted.end()-1) {
			it = vec_sorted.erase(it);
			cout << *it<<' ';
			
		}
		else {
			cout << -1<<' ';
		}
	}
	cout << -1;
}
