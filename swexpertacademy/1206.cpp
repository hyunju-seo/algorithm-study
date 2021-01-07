//https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV134DPqAA8CFAYh&categoryId=AV134DPqAA8CFAYh&categoryType=CODE
//#include<iostream>
//#include<cstring>
//
//using namespace std;
//int building[1001];
//int view[1003][256];
//int main() {
//	int t = 0;
//	while (t != 10) {
//		memset(building, -1, sizeof(building));
//		memset(view, 0, sizeof(view));
//		t += 1;
//		int w;
//		cin >> w;
//		for (int i = 0; i < w; i++) {
//			cin >> building[i];
//			for (int j = -2; j <= 2; j++) {
//				if (j == 0) continue;
//				if (i + j<0 || i + j>w) continue;
//				for (int k = 1; k <= building[i]; k++) {
//					view[i+j][k] = -1;
//				}
//			}
//		}
//		int ans = 0;
//		for (int i = 0; i < w; i++) {
//			for (int j = 1; j <= building[i]; j++) {
//				if (view[i][j] == 0) ans += 1;
//			}
//		}
//		cout <<"#"<<t<<" "<< ans << endl;
//	}
//	return 0;
//}
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int building[1001];
int main() {
	int t = 0;
	while (t != 10) {
		int ans = 0;

		memset(building, -1, sizeof(building));
		t += 1;
		int w;
		cin >> w;
		for (int i = 0; i < w; i++) {
			cin >> building[i];
		}
		for (int i = 2; i < w-2; i++) {
			int maxh = max({ building[i - 1] ,building[i - 2] ,building[i + 1] , building[i + 2] });
			if (building[i] <= maxh) continue;
			ans += building[i] - maxh;
		}
		cout << "#" << t << " " << ans << endl;
	}
	return 0;
}