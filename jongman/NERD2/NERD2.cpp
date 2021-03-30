#include<iostream>
#include<map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int c;
	cin >> c;
	while (c != 0) {
		int ret = 0;
		c -= 1;
		int n;
		cin >> n;
		map<int, int> temp;
		for (int i = 0; i < n; i++) {
			int ans = 0;
			int p, q;
			cin >> p >> q;
			if (temp.size() == 0) {
				temp.insert({ p,q });
				ans = temp.size();

			}
			else {
				auto it = temp.lower_bound(p);
				
				if (it!=temp.end()&&it->second > q) ans = temp.size();
				else {
					if (it == temp.begin()) {
						temp.insert({ p,q });
						ans = temp.size();

					}
					else {
						it--;

						
						while (it->second < q) {
							if (it == temp.begin()) {
								temp.erase(it);
								break;
							}
							auto jt = it;
							jt--;
							temp.erase(it);

							it = jt;
						}
						temp.insert({ p,q });
						ans = temp.size();
					}

				}
			}
			ret += ans;
		}
		cout << ret << "\n";
	}

}
