#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int f[4] = {2,3,0,9};

int main () {
    int t;
    ll n;

    cin >> t;
    while (t--) {
        cin >> n;
        if (n == 1) puts("0");
        else if (n <= 3) puts("1");
        else {
            int id = 0;
            for (ll m = 4; m <= n/2; m*=2, id=(id+1)%4);
            cout << f[id] << endl;
        }
    }

    return 0;
}
