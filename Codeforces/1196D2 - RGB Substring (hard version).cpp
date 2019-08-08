#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 50;

int sum1[MAX], sum2[MAX], sum3[MAX];

int main() {
    int q, k, n;
    string s = "RGB", rgb = "";

    for (int i=0; i<MAX; ++i) {
        rgb += s[i%3];
    }

    cin >> q;
    while (q--) {
        cin >> n >> k >> s;

        int ans = MAX;
        for (int i=0; s[i]; ++i) {
            if (s[i] != rgb[i]) sum1[i] = i == 0 ? 1 : 1 + sum1[i-1];
            else sum1[i] = i == 0 ? 0 : sum1[i-1];
            if (s[i] != rgb[i+1]) sum2[i] = i == 0 ? 1 : 1 + sum2[i-1];
            else sum2[i] = i == 0 ? 0 : sum2[i-1];
            if (s[i] != rgb[i+2]) sum3[i] = i == 0 ? 1 : 1 + sum3[i-1];
            else sum3[i] = i == 0 ? 0 : sum3[i-1];
            if (i+1 >= k) {
                ans = i==k-1 ? min (ans, sum1[i]) : min (ans, sum1[i] - sum1[i-k]);
                ans = i==k-1 ? min (ans, sum2[i]) : min (ans, sum2[i] - sum2[i-k]);
                ans = i==k-1 ? min (ans, sum3[i]) : min (ans, sum3[i] - sum3[i-k]);
            }
        }

        cout << ans << endl;
    }

    return 0;
}
