/*https://www.acmicpc.net/problem/6064 */
#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        //나머지 연산을 위해서 1을 뺌
        x -= 1;
        y -= 1;
        bool ok = false;
        //원래는 n,m의 최소공배수라고 해야하지만 편의상 n*m이라고 함
        for (int k = x; k < (n * m); k += m) {
            if (k % n == y) {
                //위에서 1을 뺐으므로 더해
                cout << k + 1 << '\n';
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << -1 << '\n';
        }
    }
    return 0;
}