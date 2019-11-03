#include <bits/stdc++.h>
using namespace std;

int seq[129];

void preCal () {
    for (int i=2; i<=128; ++i) {
        int k = -1;
        for (int j=1; j<i-1; ++j)
            if (seq[j] == seq[i-1])
                k = j;
        if (k == -1) seq[i] = 0;
        else seq[i] = i-k-1;
    }
}

int main() {
    int t, n;

    preCal ();

    cin >> t;
    while (t--) {
        cin >> n;
        int cnt = 0;
        for (int i=1; i<=n; ++i)
            if (seq[i] == seq[n]) ++cnt;
        cout << cnt << endl;
    }

    return 0;
}
