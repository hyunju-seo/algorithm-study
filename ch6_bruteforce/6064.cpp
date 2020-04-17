/*https://www.acmicpc.net/problem/6064 */
#include<iostream>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T != 0) {
		bool valid = true;
		T--;
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		if (m > n) {
			swap(m, n);
			swap(x, y);
		}
		int _y = x;
		int k = m - x;
		int ans = x;
		if (_y == y) {
			cout << ans<<"\n";
			continue;          //이걸 break로 해서 틀림
		}
		while((_y + k) % n != 0) {
			ans+=m;
			_y =(_y+ m-1)%n+1;       //5%5 는 5가 아니라 0이나옴 => 1빼고 1더해
		
		
			if (_y == y) {
				cout << ans<<"\n";
				valid = false;
				break;
			}	
			
		}
		if(valid==true) cout << -1 << "\n";

	}
}



