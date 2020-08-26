//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int n;
//int t[20];
//int p[20];
//vector<int> answer_price;
//vector<int> answer_index;
//정답을 찾은 경우 n+1
//불가능 한 경우 n
//마지막 날짜를 줬을때 다음 상담 일자를 찾아라
//void consult(int prev_idx) {
//	int idx = prev_idx + t[prev_idx];
//	if (idx> n) {
//		int sum = 0;
//		int last;
//		if (idx == n + 1) last = answer_index.size();
//		else last = answer_index.size() - 1;
//		for (int i=0;i<last;i++) {
//			sum += p[answer_index[i]];
//			//cout << p[i] << ' ';
//		}
//		answer_price.push_back(sum);
//		return;
//	}
//	for (int now_idx = idx;  now_idx <= n; now_idx++) {
//		answer_index.push_back(now_idx);
//		//cout << "pushindex" << now_idx << endl;
//		consult(now_idx);
//		answer_index.pop_back();
//		
//		
//
//	
//	}
//}
//오늘 상담을 할지 안할지 정하자 위에처럼 for문을 안써도 된다.(위에처럼 for문을 쓰면 중복이 생긴다)
#include <iostream>
using namespace std;
const int inf = -100000000;
int t[21];
int p[21];
int n;
int ans = 0;
void go(int day, int sum) {
    if (day == n + 1) {
        if (ans < sum) ans = sum;
        return;
    }
    if (day > n + 1) {
        return;
    }
    go(day + 1, sum);
    go(day + t[day], sum + p[day]);
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }
    go(1, 0);
    cout << ans << '\n';
    return 0;
}



//int main() {
//	cin >> n;
//	//index 1부터 시작
//	for (int i = 1; i <= n; i++) {
//		cin >> t[i] >> p[i];
//	
//	}
//	consult(0);
//	sort(answer_price.begin(), answer_price.end());
//	cout << answer_price.back() << "\n";
//	/*for (auto a : answer_price) {
//		cout << a << " ";
//	}*/
//}