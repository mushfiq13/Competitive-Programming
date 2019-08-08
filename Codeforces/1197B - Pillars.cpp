#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 10;

int a[MAX], b[MAX];

int main() {
    int n, pos, mx = 0;
    cin >> n;
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        b[i] = a[i];
        if (a[i] > mx) mx = a[i], pos = i;
    }

    sort (a+1, a+n+1);

    int l = pos-1, r = pos+1;
    pos = n-1;
    while (l >= 0 || r <= n) {
        if (b[l] == a[pos])
            --l ;
        else if (b[r] == a[pos])
            ++r ;
        else {
            puts("NO");
            return 0;
        }
        --pos ;
    }

    puts("YES");
    return 0;
}
