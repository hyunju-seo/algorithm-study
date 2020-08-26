#include<iostream>
#include<vector>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> arr1(n);
	vector<int> arr2(m);
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}
	vector<int> arr(n + m);
	int i = 0;
	int j = 0;
	int k = 0;
	//cout << 1 << endl;
	while (i <n && j<m) {
		//cout << k << endl;
		if (arr1[i] < arr2[j]) {
			arr[k] = arr1[i];
			k += 1;
			i += 1;
		}
		else {
			arr[k] = arr2[j];
			k += 1;
			j += 1;
		}
	}
	//cout << 2 << endl;

	while (i < n) {
		arr[k] = arr1[i];
		k += 1;
		i += 1;
	}
	while (j < m) {
		arr[k] = arr2[j];
		k += 1;
		j += 1;
	}
	//cout <<3<< endl;

	for (auto a : arr) {
		cout << a << " ";
	}
}