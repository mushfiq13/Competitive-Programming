#include <bits/stdc++.h>
using namespace std;

int number[305][305];

int main() {
    int n;

    cin >> n;

    int v = 1;
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            number[i][j] = v;
            ++v;
        }
    }

    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n/2 + n%2; ++j) {
            if (j>1) putchar(' ');
            printf("%d", number[j][i]);
        }
        for (int j=n/2 + n%2 + 1; j<=n; ++j) {
            printf(" %d", number[j][n-i+1]);
        }
        puts("");
    }

    return 0;
}
