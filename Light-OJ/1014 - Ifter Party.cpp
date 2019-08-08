#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, p, l;

    scanf("%d", &t);
    for (int cs = 1; cs <= t; ++cs) {
        scanf("%d %d", &p, &l);

        vector<int> v;
        p -= l;
        for (long long i = 1; i * i <= p; ++i) {
            if (p % i == 0) {
                if (p/i > l) v.push_back(p/i);
                else break;
                if (i*i != p && i > l) v.push_back(i);
            }
        }

        sort (v.begin(), v.end());

        printf("Case %d:", cs);
        if (v.size()) {
            for (int i: v)
                printf(" %d", i);
            puts("");
        }
        else puts(" impossible");
    }

    return 0;
}
