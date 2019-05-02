#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 100005

int l[MAX], r[MAX], per[MAX];
ll cum[MAX], ans[MAX];

int main()
{
    int n;

    cin >> n;
    for (int i=1; i<=n; ++i) {
        int v;
        cin >> v;
        cum[i] = cum[i-1] + v;
    }

    for (int i=1; i<=n; ++i)
        cin >> per[i];

    ll mx = 0;
    for (int i=n; i; --i) {
        int p = per[i];
        if (l[p-1] && r[p+1]) {
            r[p] = r[l[p-1]] = r[p+1];
            l[p] = l[r[p+1]] = l[p-1];
        }
        else if (l[p-1]) {
            r[p] = r[l[p-1]] = p;
            l[p] = l[p-1];
        }
        else if (r[p+1]) {
            r[p] = r[p+1];
            l[p] = l[r[p+1]] = p;
        }
        else {
            l[p] = r[p] = p;
        }
        ll tmp = cum[r[p]] - cum[l[p]-1];
        if (tmp > mx)
            mx = tmp;
        ans[i] = mx;
    }

    for (int i=2; i<=n; ++i)
        cout << ans[i] << endl;
    puts("0");

    return 0;
}
