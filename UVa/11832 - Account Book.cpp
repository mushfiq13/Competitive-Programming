#include <bits/stdc++.h>
using namespace std;

const int N = 41;
const int MAXSUM = 40001;

int nums[N], Plus[N], Minus[N];
int pos[N][2*MAXSUM], neg[N][2*MAXSUM];

int rec(int n, int f, int curSum, int i) {
    if (i == n) return f == curSum;

    int& a = pos[i][curSum + MAXSUM];
    int& b = neg[i][curSum + MAXSUM];

    if (a != -1 && b != -1) return a + b;

    a = b = 0;
    a += rec(n, f, curSum + nums[i], i+1);
    b += rec(n, f, curSum - nums[i], i+1);

    if (a) Plus[i] = '+';
    if (b) Minus[i] = '-';

    return a + b;
}
/*
5 7
1 2 3 4 5
4 15
3 5 7 11
5 12
6 7 7 1 7
0 0
*/
int main() {
    int n, f;

    while (scanf("%d %d", &n, &f)) {
        if (!n && !f) break;

        for (int i=0; i<n; ++i)
            scanf("%d", &nums[i]);

        memset(pos, -1, sizeof(pos));
        memset(neg, -1, sizeof(neg));
        memset(Plus, 0, sizeof(Plus));
        memset(Minus, 0, sizeof(Minus));

        if (!rec(n, f, 0, 0)) puts("*");
        else {
            for (int i=0; i<n; ++i) {
                if (Plus[i] && Minus[i]) putchar('?');
                else if (Plus[i]) putchar('+');
                else putchar('-');
            }
            puts("");
        }
    }
}
