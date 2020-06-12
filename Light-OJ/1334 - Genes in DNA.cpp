#include <bits/stdc++.h>
using namespace std;

vector<int> prefixFunction(string& s) {
    int n = (int)s.length();
    vector<int> pi (n+5);
    int j = 0;
    for (int i=1; i<n; ++i) {
        while (j>0 && s[i] - s[j])
            j = pi[j-1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}

void Count(int n, int m, vector<int>& pi, vector<int>& pp) {
    for (int i=n; i<m; ++i) {
        int cur = pi[i];
        stack<int> st;
        while (cur) {
            st.push(cur);
            if (pp[cur]) break;
            cur = pi[cur-1];
        }
        if (st.empty()) continue;
        if (!pp[st.top()]) pp[st.top()] = 1;
        int cnt = pp[st.top()];
        st.pop();
        while (!st.empty()) {
            pp[st.top()] = ++cnt;
            st.pop();
        }
    }
}

int main() {
    int T, n;
    string t, s;

    scanf("%d", &T);
    for (int Case=1; Case<=T; ++Case) {
        cin >> t >> s;

        string a = s + '#' + t;
        vector<int> pi1 = prefixFunction(a);

        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());

        string b = s + '#' + t;
        vector<int> pi2 = prefixFunction(b);

        int n = (int)s.length();
        int m = (int)b.length();

        int i = n+1, j = m-1;
        while (i < j) {
            swap(pi2[i], pi2[j]);
            ++i, --j;
        }

        vector<int> pp1 (n+5), pp2 (n+5);
        Count(n+1, m, pi1, pp1);
        Count(n+1, m, pi2, pp2);

        long long ans = 0;
        for (int i=n+1; i<m-1; ++i) {
            int x = pp1[pi1[i]], y = pp2[pi2[i+1]];
            if (pi1[i] == n) --x;
            if (pi2[i+1] == n) --y;
            ans += x * y;
        }

        printf("Case %d: %lld\n", Case, ans);
    }
}
