/*https://www.acmicpc.net/problem/6064 */
#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        //������ ������ ���ؼ� 1�� ��
        x -= 1;
        y -= 1;
        bool ok = false;
        //������ n,m�� �ּҰ������� �ؾ������� ���ǻ� n*m�̶�� ��
        for (int k = x; k < (n * m); k += m) {
            if (k % n == y) {
                //������ 1�� �����Ƿ� ����
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