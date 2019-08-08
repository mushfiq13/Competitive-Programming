#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 2e5 + 10;

int a[MAX];

int main() {
    int q, n, k;

    cin >> q;
    while (q--) {
        cin >> n >> k;
        vector<int> v;
        for (int i=1; i<=n; ++i) {
            cin >> a[i];
            if (a[i]%2) v.push_back(i);
        }

        if (v.size()%2 == k%2 && v.size()>=k) {
            puts("YES");
            for (int i = 0; i < k-1; ++i)
                printf("%d ", v[i]);
            printf("%d\n", n);
        }
        else
            puts("NO");
    }

    return 0;
}
