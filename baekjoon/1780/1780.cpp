#include<iostream>
#include<cmath>
using namespace std;
int a[3000][3000];
int zeronum = 0;
int minusnum = 0;
int plusnum = 0;
void paper(int rstart, int rend, int cstart, int cend) {
  //  cout << rstart << rend << cstart << cend << endl;
    bool ans = true;
    int n = a[rstart][cstart];
    for (int i = rstart; i <= rend; i++) {
        for (int j = cstart; j <= cend; j++) {
            if (a[i][j] != n) {
                ans = false; 
            }
        }
    }
    if (ans) {
        if (n == 0) zeronum++;
        if (n == 1) plusnum++;
        if (n == -1) minusnum++;
        return;
    }
    int width = rend - rstart + 1 ;
    int nums = width / 3;
    int r = rstart;
    for (int i = 0; i < 3; i++) {
        int c = cstart;

        for (int j = 0; j < 3; j++) {
            paper(r, r + nums - 1, c, c + nums - 1);
            c = c + nums;
        }
        r = r + nums;
    }


}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    paper(0, n - 1, 0, n - 1);
    cout << minusnum << "\n" << zeronum << "\n" << plusnum << "\n";
}