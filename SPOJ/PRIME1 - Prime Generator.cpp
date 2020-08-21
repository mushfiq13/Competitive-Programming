#include <bits/stdc++.h>
using namespace std;

void segmentedSieve(int L, int R) {
    vector<bool> segment (R-L+1, true);
    for (int i=3; i*i <= R; i += 2)
        for (int j=max(i*i, (L+i-1)/i * i); j <= R; j += i)
            segment[j-L] = false;

    if (L == 1) segment[0] = false;
    for (int i=0; i<R-L+1; ++i)
        if ((i+L==2 || (i+L) & 1) && segment[i])
        printf("%d\n", i+L);
}

int main() {
    int t, l, r;

    cin >> t;
    while (t--) {
        cin >> l >> r;
        segmentedSieve(l, r);
        if (t) puts("");
    }
}
