#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    string s, t, p;

    cin >> q;
    while (q--) {
        cin >> s >> t >> p;

        int cnt[27] = {};
        for (int i=0; p[i]; ++i)
            ++cnt[p[i]-'a'] ;

        for (int i=0; t[i]; ++i) {
            if (s[i] != t[i] && !cnt[t[i]-'a']) break;
            if (s[i] != t[i]) {
                --cnt[t[i]-'a'] ;
                string tmp = "";
                for (int j=0; j<i; ++j)
                    tmp += t[j];
                tmp += t[i];
                for (int j=i; s[j]; ++j)
                    tmp += s[j];
                s = tmp;
            };
        }

        if (s == t) puts("YES");
        else puts("NO");
    }

    return 0;
}
