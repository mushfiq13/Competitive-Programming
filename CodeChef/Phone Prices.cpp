#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    int a[110];

    cin >> t;
    while (t--) {
        cin >> n;
        int day = 0;
        for (int i=1; i<=n; ++i) {
            cin >> a[i];
            int mn = 1000;
            for (int j=i-1; j>=1 && j>=i-5; --j)
                mn = min (mn, a[j]);
            if (mn > a[i]) ++day;
        }
        cout << day << endl;
    }
    return 0;
}
