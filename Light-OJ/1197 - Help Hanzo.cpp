#include <bits/stdc++.h>
using namespace std;

vector<bool> segmentedSieve(long long L, long long R) {
    vector<bool> segment (R-L+1, true);
    for (long long i=2; i*i <= R; i = (i&1) ? i+2 : i+1)
        for (long long j=max(i*i, (L+i-1)/i * i); j <= R; j += i)
            segment[j-L] = false;
    if (L == 1)
        segment[0] = false;
    return segment;
}

int main() {
    int t;
    long long a, b;

    scanf("%d", &t);
    for (int Case=1; Case<=t; ++Case) {
        scanf("%lld %lld", &a, &b);
        vector<bool> segment = segmentedSieve(a, b);
        int cnt = 0;
        for (bool x : segment)
            cnt += x;
        printf("Case %d: %d\n", Case, cnt);
    }
}
