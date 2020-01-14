#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, s, w1, w2, w3;

    cin >> t;
    while (t--) {
        cin >> s >> w1 >> w2 >> w3;
        if (w1+w2+w3 <= s)
            puts("1");
        else if (w1+w2 <= s || w2+w3 <= s)
            puts("2");
        else
            puts("3");
    }

    return 0;
}
