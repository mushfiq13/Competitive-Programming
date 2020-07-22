#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int, pair<int, int>>> v;

    int w, s;
    for (int i=1; ~scanf("%d %d", &w, &s); ++i)
        v.push_back({w, {s, i}});

    sort(v.begin(), v.end());

    int n = v.size();
    vector<int> L(n, 1), p (n);

    int pos, mx = 0;
    for (int i=0; i<n; ++i) {
        p[i] = i;
        int w1 = v[i].first, s1 = v[i].second.first;
        for (int j=0; j<i; ++j) {
            int w2 = v[j].first, s2 = v[j].second.first;
            if (s1 < s2 && w1 > w2 && L[i] < L[j]+1)
                L[i] = L[j] + 1, p[i] = j;
        }
        if (L[i] > mx) mx = L[i], pos = i;
    }

    vector<int> ans;
    while (p[pos] - pos)
        ans.push_back(v[pos].second.second), pos = p[pos];
    ans.push_back(v[pos].second.second);

    cout << ans.size() << endl;
    for (int i=ans.size()-1; i>=0; --i)
        cout << ans[i] << endl;
}
