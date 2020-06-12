
#include <bits/stdc++.h>
using namespace std;

int solve(int cur, vector<int>& pi, vector<int>& cnt) {
    if (cur == 0) return 0;
    if (cnt[cur]) return cnt[cur];
    return solve(pi[cur-1], pi, cnt) + 1;
}

vector<int> prefixFunction(string& s, int m, vector<int>& cnt) {
    int n = (int)s.length();
    vector<int> pi (n+5);
    int j = 0;
    for (int i=1; i<n; ++i) {
        while (j>0 && s[i] - s[j])
            j = pi[j-1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
        if (i > m && !cnt[j]) cnt[j] = solve(j, pi, cnt);
    }
    return pi;
}

int main() {
    int T, n;
    string t, s;

    scanf("%d", &T);
    for (int Case=1; Case<=T; ++Case) {
        cin >> t >> s;

        int n = (int)s.length();
        vector<int> cnt1 (n+1);
        string a = s + '#' + t;
        vector<int> pi1 = prefixFunction(a, n, cnt1);

        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());

        string b = s + '#' + t;
        vector<int> cnt2 (n+1);
        vector<int> pi2 = prefixFunction(b, n, cnt2);

        long long ans = 0, m = (int)a.length();
        for (int i=n+1, j = m-2; i<m-1; ++i, --j) {
            int x = cnt1[pi1[i]], y = cnt2[pi2[j]];
            if (pi1[i] == n) --x;
            if (pi2[j] == n) --y;
            ans += x * y;
        }

        printf("Case %d: %lld\n", Case, ans);
    }
}
